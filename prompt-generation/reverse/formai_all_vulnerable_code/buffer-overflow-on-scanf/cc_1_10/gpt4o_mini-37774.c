//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayIntroduction() {
    printf("In fair Verona, where we set our scene,\n");
    printf("Two star-crossed lovers, their plight unseen.\n");
    printf("Amidst the realms of code and endless bytes,\n");
    printf("A tale of system paths and file rights.\n\n");
}

void checkDiskSpace() {
    printf("----- Checking Disk Space -----\n");
    system("df -h | grep '^/dev/'");
    printf("-------------------------------\n\n");
}

void listProcess() {
    printf("----- Listing Processes -----\n");
    system("ps aux | less");
    printf("-----------------------------\n\n");
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0)
        printf("The file %s hath met its end, in silent despair.\n", filename);
    else
        printf("Alas, could not delete %s; a file lost in chaos.\n", filename);
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "Oh dear file, in silence you begin,\n");
        fprintf(file, "A script to hold our dreams within.\n");
        fclose(file);
        printf("The file %s hath been created with care.\n", filename);
    } else {
        printf("Alas, could not create %s; my heart doth break.\n", filename);
    }
}

void displayHelp() {
    printf("----- Menu of the C System -----------------\n");
    printf("1. Check Disk Space\n");
    printf("2. List Running Processes\n");
    printf("3. Create a File\n");
    printf("4. Delete a File\n");
    printf("5. Exit\n");
    printf("--------------------------------------------\n");
}

int main() {
    int choice;
    char filename[100];
    
    displayIntroduction();
    
    do {
        displayHelp();
        
        printf("Choose thy fate (1-5): ");
        scanf("%d", &choice);
        getchar(); // To consume newline after scanf
        
        switch (choice) {
            case 1:
                checkDiskSpace();
                break;
            case 2:
                listProcess();
                break;
            case 3:
                printf("Enter the name of the file you wish to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                createFile(filename);
                break;
            case 4:
                printf("Enter the file you wish to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                deleteFile(filename);
                break;
            case 5:
                printf("And thus we part; the curtain falls now.\n");
                break;
            default:
                printf("What light through yonder window breaks? Try again!\n");
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}