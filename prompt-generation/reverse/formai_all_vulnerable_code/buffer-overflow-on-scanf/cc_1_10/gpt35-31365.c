//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct File {
    char fname[20];
    int fsize;
} File;

typedef struct Node {
    File data;
    struct Node* next;
} Node;

Node* head = NULL;

void push(File data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void displayList() {
    Node* current = head;
    while(current != NULL) {
        printf("File Name: %s\n", current->data.fname);
        printf("File Size: %d KB\n", current->data.fsize);
        current = current->next;
    }
}

void backup() {
    FILE *fp1, *fp2;
    char c;
    File f;

    printf("Enter file name to be backed up: ");
    scanf("%s", f.fname);

    fp1 = fopen(f.fname, "r");

    if(fp1 == NULL) {
        printf("File does not exist.\n");
        return;
    }

    fseek(fp1, 0L, SEEK_END);
    f.fsize = ftell(fp1) / 1024;
    rewind(fp1);

    char fname[20];
    sprintf(fname, "backup_%s", f.fname);
    fp2 = fopen(fname, "w");

    while((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    push(f);

    printf("%s backed up successfully!\n", f.fname);
}

void deleteFile() {
    char fname[20];
    printf("Enter file name to be deleted: ");
    scanf("%s", fname);

    if(remove(fname) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Failed to delete the file.\n");
    }
}

void displayMenu() {
    printf("\nFile Backup System\n");
    printf("1. Backup a file\n");
    printf("2. Delete a file\n");
    printf("3. View backup history\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                backup();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                displayList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}