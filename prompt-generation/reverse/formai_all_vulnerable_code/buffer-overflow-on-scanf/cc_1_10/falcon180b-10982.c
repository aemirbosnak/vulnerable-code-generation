//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>

int main() {
    int choice;
    char filename[100];
    FILE *fp;

    printf("Welcome to the Ebook Reader 3000!\n");
    printf("Please enter the name of the ebook you would like to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 0;
    }

    printf("\nEbook Title: ");
    fscanf(fp, "%s", filename);
    printf("\nAuthor: ");
    fscanf(fp, "%s", filename);
    printf("\nPublished Year: ");
    fscanf(fp, "%d", &filename);

    printf("\nTable of Contents:\n");
    rewind(fp);
    while (fgets(filename, sizeof(filename), fp)!= NULL) {
        printf("%s\n", filename);
    }

    printf("\nPress 1 to start reading.\nPress 2 to save your progress.\nPress 3 to exit.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enjoy your reading!\n");
            break;
        case 2:
            printf("Your progress has been saved.\n");
            break;
        case 3:
            printf("Thank you for using the Ebook Reader 3000.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    fclose(fp);
    return 0;
}