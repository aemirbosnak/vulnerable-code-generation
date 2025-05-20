//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>

int main() {
    FILE *filePtr;
    char fileName[20], data[100];
    int choice;

    printf("Welcome to my visionary file handling program!\n");

    do {
        printf("1. Create a new file\n");
        printf("2. Write to a file\n");
        printf("3. Read from a file\n");
        printf("4. Append to a file\n");
        printf("5. Delete a file\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the file to create: ");
                scanf("%s", fileName);

                filePtr = fopen(fileName, "w");

                if(filePtr == NULL) {
                    printf("Error creating the file!");
                } else {
                    printf("File created successfully!");
                    fclose(filePtr);
                }

                break;
            
            case 2:
                printf("Enter the name of the file to write to: ");
                scanf("%s", fileName);

                filePtr = fopen(fileName, "w");

                if(filePtr == NULL) {
                    printf("Error opening the file!");
                } else {
                    printf("Enter data to write to the file (max 100 chars): ");
                    scanf("%s", data);
                    fprintf(filePtr, "%s", data);
                    fclose(filePtr);
                    printf("Data written to the file successfully!");
                }

                break;

            case 3:
                printf("Enter the name of the file to read from: ");
                scanf("%s", fileName);

                filePtr = fopen(fileName, "r");

                if(filePtr == NULL) {
                    printf("Error opening the file!");
                } else {
                    fgets(data, 100, filePtr);
                    printf("Data read from the file: %s", data);
                    fclose(filePtr);
                }

                break;

            case 4:
                printf("Enter the name of the file to append to: ");
                scanf("%s", fileName);

                filePtr = fopen(fileName, "a");

                if(filePtr == NULL) {
                    printf("Error opening the file!");
                } else {
                    printf("Enter data to append to the file (max 100 chars): ");
                    scanf("%s", data);
                    fprintf(filePtr, "%s", data);
                    fclose(filePtr);
                    printf("Data appended to the file successfully!");
                }

                break;

            case 5:
                printf("Enter the name of the file to delete: ");
                scanf("%s", fileName);

                if(remove(fileName) == 0) {
                    printf("File deleted successfully!");
                } else {
                    printf("Error deleting the file!");
                }

                break;

            case 6:
                printf("Thank you for using my visionary file handling program!");
                break;

            default:
                printf("Invalid choice, please try again.");
                break;
        }

        printf("\n");

    } while(choice != 6);

    return 0;
}