//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    FILE *file;
    char data[50];

    printf("Welcome to Decentralized File Handling Program\n");

    printf("1. Write Data to File\n");
    printf("2. Read Data from File\n");
    printf("3. Modify Data in File\n");
    printf("4. Delete Data from File\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            file = fopen("/usr/local/data.txt", "w");
            if(file == NULL) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
            printf("Enter data to write to file: ");
            scanf("%s", data);
            fprintf(file, "%s", data);
            printf("Data written to file successfully\n");
            fclose(file);
            break;
        case 2:
            file = fopen("/usr/local/data.txt", "r");
            if(file == NULL) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
            fscanf(file, "%s", data);
            printf("Data read from file: %s\n", data);
            fclose(file);
            break;
        case 3:
            file = fopen("/usr/local/data.txt", "r+");
            if(file == NULL) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
            printf("Enter new data: ");
            scanf("%s", data);
            fprintf(file, "%s", data);
            printf("Data modified successfully\n");
            fclose(file);
            break;
        case 4:
            if(remove("/usr/local/data.txt") == 0) {
                printf("Data deleted successfully\n");
            } else {
                perror("Error deleting data");
            }
            break;
        case 5:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}