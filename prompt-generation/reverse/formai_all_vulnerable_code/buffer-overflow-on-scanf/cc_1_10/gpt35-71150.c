//FormAI DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    char entry[1000];
} DiaryEntry;

int main() {
    int choice, option, i;
    char filename[15];
    FILE *fp;
    DiaryEntry entry;
    printf("Welcome to your digital diary!\n\n");
    do {
        printf("\n---------------------------------\n");
        printf("Enter the number of the operation you want to perform:\n");
        printf("1. Create a new diary entry\n");
        printf("2. View an existing diary entry\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the date of your entry (YY/MM/DD): ");
                scanf("%d/%d/%d", &entry.year, &entry.month, &entry.day);
                printf("\nWrite your entry:\n");
                getchar();
                fgets(entry.entry, 1000, stdin);
                sprintf(filename, "%d%d%d.txt", entry.year, entry.month, entry.day);
                fp = fopen(filename, "w");
                if(fp == NULL) {
                    printf("\nError creating file.\n");
                    exit(0);
                }
                fprintf(fp, "%d/%d/%d:\n%s", entry.year, entry.month, entry.day, entry.entry);
                fclose(fp);
                printf("\nEntry saved successfully!");
                break;
            case 2:
                printf("\nEnter the date of the entry you want to view (YY/MM/DD): ");
                scanf("%d/%d/%d", &entry.year, &entry.month, &entry.day);
                sprintf(filename, "%d%d%d.txt", entry.year, entry.month, entry.day);
                fp = fopen(filename, "r");
                if(fp == NULL) {
                    printf("\nError opening file.\n");
                    exit(0);
                }
                printf("\nEntry found:\n");
                while(fgets(entry.entry, 1000, fp)) {
                    printf("%s", entry.entry);
                }
                fclose(fp);
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
        printf("\nDo you want to perform another operation? (1 for yes, 0 for no): ");
        scanf("%d", &option);
    } while(option == 1);
    return 0;
}