//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    char filename[100];
    char content[1000];
    int choice;

    printf("Welcome to FILE HANDLING SYSTEM\n");
    printf("--------------------------------\n");

    while(1) {
        printf("Choose what you want to do:\n");
        printf("1. Create a file\n");
        printf("2. Write to a file\n");
        printf("3. Read from a file\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                if(fp == NULL) {
                    printf("Error creating file!\n");
                    exit(1);
                }
                else {
                    printf("File created successfully!\n");
                    fclose(fp);
                }
                break;

            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter content: ");
                scanf("%s", content);
                fp = fopen(filename, "a");
                if(fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                else {
                    fprintf(fp, "%s\n", content);
                    printf("Content written successfully!\n");
                    fclose(fp);
                }
                break;

            case 3:
                printf("Enter filename: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if(fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                else {
                    printf("File contents:\n");
                    char c = fgetc(fp);
                    while(c != EOF) {
                        printf("%c", c);
                        c = fgetc(fp);
                    }
                    fclose(fp);
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}