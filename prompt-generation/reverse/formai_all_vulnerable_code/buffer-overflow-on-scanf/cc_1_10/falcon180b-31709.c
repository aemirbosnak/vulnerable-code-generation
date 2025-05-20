//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to read the ebook file
void read_ebook(char *filename) {
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
        i++;
        if (i == 80) {
            printf("\n");
            i = 0;
        }
    }
    fclose(fp);
}

// Function to display the menu
void display_menu() {
    printf("Ebook reader\n");
    printf("1. Read ebook\n");
    printf("2. Exit\n");
}

// Main function
int main() {
    char filename[100];
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the ebook file name: ");
                scanf("%s", filename);
                read_ebook(filename);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}