//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char entry[1000], date[20];
    time_t t;
    struct tm* tm_info;
    time(&t);
    tm_info = localtime(&t);
    strftime(date, 20, "%Y-%m-%d", tm_info);
    
    printf("Welcome to your Digital Diary!\n");
    printf("==============================\n");
    printf("Today's date is %s\n\n", date);
    
    FILE *fp;
    fp = fopen(date, "a+");
    if (fp == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    
    while(1){
        printf("Please select an option:\n");
        printf("1. Add a new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                fflush(stdin);
                printf("\nEnter your new entry:\n");
                fgets(entry, 1000, stdin);
                fprintf(fp, "%s", entry);
                printf("\nYour entry has been saved!\n\n");
                break;
            
            case 2:
                printf("\nHere are your previous entries:\n");
                rewind(fp);
                char c = fgetc(fp);
                while (c != EOF){
                    printf("%c", c);
                    c = fgetc(fp);
                }
                printf("\n\n");
                break;

            case 3:
                printf("\nGoodbye!\n");
                fclose(fp);
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
    return 0;
}