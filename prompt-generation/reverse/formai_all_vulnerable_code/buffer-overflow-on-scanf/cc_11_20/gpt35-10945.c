//FormAI DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100], title[50], author[50], isbn[20];
    int pages, choice, i;

    printf("Welcome to the C Ebook Reader!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new ebook\n");
        printf("2. View all ebooks\n");
        printf("3. Search ebooks by author\n");
        printf("4. Search ebooks by title\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter the ebook filename: ");
            scanf("%s", filename);

            FILE *fp = fopen(filename, "w");
            if(fp == NULL) {
                printf("\nError creating the ebook file!\n");
                continue;
            }

            printf("\nEnter the ebook title: ");
            scanf("%s", title);

            printf("\nEnter the ebook author: ");
            scanf("%s", author);

            printf("\nEnter the ebook ISBN: ");
            scanf("%s", isbn);

            printf("\nEnter the number of pages: ");
            scanf("%d", &pages);

            fprintf(fp, "Title: %s\n", title);
            fprintf(fp, "Author: %s\n", author);
            fprintf(fp, "ISBN: %s\n", isbn);
            fprintf(fp, "Pages: %d\n", pages);

            printf("\nEbook added successfully!\n");

            fclose(fp);
        }
        else if(choice == 2) {
            printf("\nList of all ebooks:\n");

            FILE *fp;
            char line[100];

            fp = popen("ls *.ebook", "r");
            if(fp == NULL) {
                printf("\nError opening the ebook directory!\n");
                continue;
            }

            while(fgets(line, sizeof(line), fp) != NULL) {
                line[strcspn(line, "\r\n")] = 0;
                printf("%s\n", line);
            }

            pclose(fp);
        }
        else if(choice == 3) {
            printf("\nEnter the author name: ");
            scanf("%s", author);

            printf("\nEbooks by %s:\n", author);

            FILE *fp;
            char line[100];

            fp = popen("ls *.ebook", "r");
            if(fp == NULL) {
                printf("\nError opening the ebook directory!\n");
                continue;
            }

            while(fgets(line, sizeof(line), fp) != NULL) {
                line[strcspn(line, "\r\n")] = 0;

                FILE *fp_ebook = fopen(line, "r");
                if(fp_ebook == NULL) {
                    printf("\nError opening the ebook file!\n");
                    continue;
                }

                char ebook_author[50];
                fscanf(fp_ebook, "Title: %*s Author: %s ISBN: %*s Pages: %*d", ebook_author);

                if(strcmp(author, ebook_author) == 0) {
                    printf("%s\n", line);
                }

                fclose(fp_ebook);
            }

            pclose(fp);
        }
        else if(choice == 4) {
            printf("\nEnter the ebook title: ");
            scanf("%s", title);

            printf("\nEbooks with the title %s:\n", title);

            FILE *fp;
            char line[100];

            fp = popen("ls *.ebook", "r");
            if(fp == NULL) {
                printf("\nError opening the ebook directory!\n");
                continue;
            }

            while(fgets(line, sizeof(line), fp) != NULL) {
                line[strcspn(line, "\r\n")] = 0;

                FILE *fp_ebook = fopen(line, "r");
                if(fp_ebook == NULL) {
                    printf("\nError opening the ebook file!\n");
                    continue;
                }

                char ebook_title[50];
                fscanf(fp_ebook, "Title: %s Author: %*s ISBN: %*s Pages: %*d", ebook_title);

                if(strcmp(title, ebook_title) == 0) {
                    printf("%s\n", line);
                }

                fclose(fp_ebook);
            }

            pclose(fp);
        }
        else if(choice == 5) {
            printf("\nThank you for using the C Ebook Reader!\n");
            break;
        }
        else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}