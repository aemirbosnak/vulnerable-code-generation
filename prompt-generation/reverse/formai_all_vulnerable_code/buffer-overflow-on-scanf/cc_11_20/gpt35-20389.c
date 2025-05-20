//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50];
    char str[1000];
    char ch;
    int choice, num, i;

    printf("Greetings! Welcome to my file handling program.\n");

    do {
        printf("\n*** File Handling Menu ***\n");
        printf("1. Create a file\n");
        printf("2. Read from a file\n");
        printf("3. Write to a file\n");
        printf("4. Append to a file\n");
        printf("5. Delete a file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the file to create: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Failed to create the file!\n");
                    exit(1);
                }
                printf("File created successfully!\n");
                fclose(fp);
                break;

            case 2:
                printf("Enter the name of the file to read from: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Failed to open the file!\n");
                    exit(1);
                }
                printf("Contents of the file:\n");
                while ((ch = fgetc(fp)) != EOF)
                    putchar(ch);
                fclose(fp);
                break;

            case 3:
                printf("Enter the name of the file to write to: ");
                scanf("%s", filename);
                printf("Enter the text to write: ");
                scanf("%s", str);
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Failed to open the file!\n");
                    exit(1);
                }
                fputs(str, fp);
                printf("Text written successfully!\n");
                fclose(fp);
                break;

            case 4:
                printf("Enter the name of the file to append to: ");
                scanf("%s", filename);
                printf("Enter the text to append: ");
                scanf("%s", str);
                fp = fopen(filename, "a");
                if (fp == NULL) {
                    printf("Failed to open the file!\n");
                    exit(1);
                }
                fputs(str, fp);
                printf("Text appended successfully!\n");
                fclose(fp);
                break;

            case 5:
                printf("Enter the name of the file to delete: ");
                scanf("%s", filename);
                if (remove(filename) == 0)
                    printf("File deleted successfully!\n");
                else
                    printf("Failed to delete the file!\n");
                break;

            case 6:
                printf("Thank you for using my program!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 6);

    return 0;
}