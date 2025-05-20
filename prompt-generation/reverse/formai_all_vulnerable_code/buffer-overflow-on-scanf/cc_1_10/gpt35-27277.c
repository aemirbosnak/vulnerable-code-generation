//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct diary {
    char date[11];
    char entry[1000];
};

int main(){
    int option = 0;
    FILE *file;
    struct diary today;

    printf("Welcome to your Daily Digital Diary!\n");

    while(option != 3) {
        printf("\nChoose an option:\n");
        printf("1. Write an Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter date (DD/MM/YYYY): ");
                scanf("%s", today.date);
                printf("Start writing your entry: \n");
                scanf("%c", &today.entry[0]);
                scanf("%[^\n]", today.entry);

                file = fopen(today.date, "w");

                if(file != NULL) {
                    fprintf(file, "%s\n%s", today.date, today.entry);
                    fclose(file);
                    printf("Diary entry saved successfully!\n");
                } else {
                    printf("Error opening file!\n");
                }

                break;
            case 2:
                printf("\nEnter date (DD/MM/YYYY): ");
                scanf("%s", today.date);

                file = fopen(today.date, "r");

                if(file != NULL) {
                    fgets(today.date, 11, file);
                    fgets(today.entry, 1000, file);
                    fclose(file);

                    printf("\nDate: %s\n\n%s\n", today.date, today.entry);
                } else {
                    printf("No entry found for that date.\n");
                }

                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option!\n");
                break;
        }
    }

    return 0;
}