//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include<stdio.h>

// Structure to hold diary information
struct Diary {
    int date;
    char content[1000];
};

int main() {
    printf("###############################################################\n");
    printf("#                                                             #\n");
    printf("#                  My Digital Diary                            #\n");
    printf("#                                                             #\n");
    printf("###############################################################\n");


    int choice;
    struct Diary diary;

    do {
        printf("Select an option:\n");
        printf("1. Create a new entry\n");
        printf("2. View an existing entry\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter today's date (DDMMYY): ");
                scanf("%d", &diary.date);
                printf("Enter your entry (max 1000 characters): ");
                getchar(); // Clear the input buffer
                fgets(diary.content, 1000, stdin);
                printf("Entry added successfully!\n");
                break;

            case 2:
                printf("Enter the date of the entry to view (DDMMYY): ");
                scanf("%d", &diary.date);
                printf("\nEntry for %d:\n%s\n", diary.date, diary.content);
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}