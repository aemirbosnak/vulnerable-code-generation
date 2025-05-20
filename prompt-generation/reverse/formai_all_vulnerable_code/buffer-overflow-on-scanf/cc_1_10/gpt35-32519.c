//FormAI DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to create a new diary entry
void newEntry(void) {
    FILE *fp;
    char fileName[50];
    char date[15];
    char entry[500];
    
    printf("Enter the date of the entry (DD/MM/YYYY format): ");
    scanf("%s", date);
    
    //create a file name based on the date of entry
    sprintf(fileName, "%s-diary.txt", date);
    
    //open the file for writing
    fp = fopen(fileName, "w");
    
    if (fp == NULL) {
        printf("Error creating diary entry.\n");
        return;
    }
    
    printf("Enter your thoughts for the day (max 500 characters): ");
    fflush(stdin);
    fgets(entry, 500, stdin);
    
    //write the entry to the file and close it
    fprintf(fp, "%s", entry);
    fclose(fp);
    
    printf("Diary entry created successfully.\n");
}

//function to view an existing diary entry
void viewEntry(void) {
    FILE *fp;
    char fileName[50];
    char date[15], line[500];

    printf("Enter the date of the entry you want to view (DD/MM/YYYY format): ");
    scanf("%s", date);
    
    //create a file name based on the date of entry
    sprintf(fileName, "%s-diary.txt", date);
    
    //open the file for reading
    fp = fopen(fileName, "r");
    
    if (fp == NULL) {
        printf("Diary entry not found for given date.\n");
        return;
    }
    
    printf("========== Diary Entry for %s ==========\n\n", date);
    
    //read the contents of the file and print them to console
    while (fgets(line, 500, fp) != NULL) {
        printf("%s", line);
    }
    
    fclose(fp);
}

int main(void) {
    int choice;
    
    //display menu and prompt for user input
    do {
        printf("======= DIGITAL DIARY =======\n");
        printf("1. Create a new diary entry\n");
        printf("2. View an existing diary entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                newEntry();
                printf("\n");
                break;
            case 2:
                viewEntry();
                printf("\n");
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}