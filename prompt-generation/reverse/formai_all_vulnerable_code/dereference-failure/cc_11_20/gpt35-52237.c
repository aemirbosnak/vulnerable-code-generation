//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    char title[100];
    char author[100];
    char genre[100];
    int pages;
    float rating;
};

int main(){
    int n = 0, choice = 0;
    struct Book *library = malloc(n*sizeof(struct Book));
    char filename[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }
    char line[255];
    while(fgets(line, sizeof(line), fp)){
        sscanf(line, "%[^,],%[^,],%[^,],%d,%f", (library+n)->title, (library+n)->author, (library+n)->genre, &(library+n)->pages, &(library+n)->rating);
        n++;
        library = realloc(library, (n+1)*sizeof(struct Book));
    }
    fclose(fp);
    printf("Successfully read %d book(s) from the file.\n", n);
    while(choice!=4){
        printf("\nWhat do you want to do?\n1. View book information\n2. Add new book\n3. Update book rating\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("View information by:\n1. Title\n2. Author\n3. Genre\n");
                int view_choice;
                scanf("%d", &view_choice);
                char search[100];
                printf("Enter search term: ");
                scanf("%s", search);
                switch(view_choice){
                    case 1:
                        for(int i=0; i<n; i++){
                            if(strcmp((library+i)->title, search) == 0){
                                printf("Title: %s\n", (library+i)->title);
                                printf("Author: %s\n", (library+i)->author);
                                printf("Genre: %s\n", (library+i)->genre);
                                printf("Pages: %d\n", (library+i)->pages);
                                printf("Rating: %.2f\n\n", (library+i)->rating);
                            }
                        }
                        break;
                    case 2:
                        for(int i=0; i<n; i++){
                            if(strcmp((library+i)->author, search) == 0){
                                printf("Title: %s\n", (library+i)->title);
                                printf("Author: %s\n", (library+i)->author);
                                printf("Genre: %s\n", (library+i)->genre);
                                printf("Pages: %d\n", (library+i)->pages);
                                printf("Rating: %.2f\n\n", (library+i)->rating);
                            }
                        }
                        break;
                    case 3:
                        for(int i=0; i<n; i++){
                            if(strcmp((library+i)->genre, search) == 0){
                                printf("Title: %s\n", (library+i)->title);
                                printf("Author: %s\n", (library+i)->author);
                                printf("Genre: %s\n", (library+i)->genre);
                                printf("Pages: %d\n", (library+i)->pages);
                                printf("Rating: %.2f\n\n", (library+i)->rating);
                            }
                        }
                        break;
                    default:
                        printf("Invalid option selected.\n");
                        break;
                }
                break;
            case 2:
                printf("Enter information for the new book:\n");
                printf("Title: ");
                scanf("%s", (library+n)->title);
                printf("Author: ");
                scanf("%s", (library+n)->author);
                printf("Genre: ");
                scanf("%s", (library+n)->genre);
                printf("Number of pages: ");
                scanf("%d", &(library+n)->pages);
                printf("Rating: ");
                scanf("%f", &(library+n)->rating);
                n++;
                library = realloc(library, (n+1)*sizeof(struct Book));
                printf("Book added successfully.\n");
                break;
            case 3:
                printf("Enter the title of the book to update rating: ");
                char update_title[100];
                scanf("%s", update_title);
                int update_index = -1;
                for(int i=0; i<n; i++){
                    if(strcmp((library+i)->title, update_title) == 0){
                        update_index = i;
                        break;
                    }
                }
                if(update_index == -1){
                    printf("No book found with the given title.\n");
                }
                else{
                    printf("Enter the new rating: ");
                    float new_rating;
                    scanf("%f", &new_rating);
                    (library+update_index)->rating = new_rating;
                    printf("Rating updated successfully.\n");
                }
                break;
            case 4:
                printf("Thank you for using the ebook reader!\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    }
    free(library);
    return 0;
}