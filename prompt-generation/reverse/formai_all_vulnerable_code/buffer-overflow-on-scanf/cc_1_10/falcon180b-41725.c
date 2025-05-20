//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int size;
    char type;
} File;

void create(File* file, int num) {
    printf("Enter the name of the file: ");
    scanf("%s", file->name);
    printf("Enter the size of the file: ");
    scanf("%d", &file->size);
    printf("Enter the type of the file (0 for text, 1 for binary): ");
    scanf("%c", &file->type);
    printf("File %s created successfully.\n", file->name);
}

void display(File file) {
    printf("Name: %s\n", file.name);
    printf("Size: %d bytes\n", file.size);
    printf("Type: %c\n", file.type);
}

int main() {
    File file;
    int choice, num;

    do {
        system("clear");
        printf("\n\n");
        printf("1. Create file\n");
        printf("2. Display file\n");
        printf("3. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of files to create: ");
                scanf("%d", &num);
                for(int i=0; i<num; i++) {
                    create(&file, i+1);
                }
                break;
            case 2:
                printf("Enter the number of the file to display: ");
                scanf("%d", &num);
                display(file);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= 3);

    return 0;
}