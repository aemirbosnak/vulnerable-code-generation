//FormAI DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct painting {
    char title[50];
    char artist[50];
    char medium[50];
    int year;
} Painting;

void createPaintingFile() {
    FILE* paintingFile = fopen("paintings.txt", "w");
    if (paintingFile == NULL) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }
    fputs("Title,Artist,Medium,Year\n", paintingFile);
    fclose(paintingFile);
    printf("Paintings file created!\n");
}

void addPainting() {
    Painting newPainting;
    printf("Enter painting title: ");
    fgets(newPainting.title, 50, stdin);
    printf("Enter artist name: ");
    fgets(newPainting.artist, 50, stdin);
    printf("Enter painting medium: ");
    fgets(newPainting.medium, 50, stdin);
    printf("Enter painting year: ");
    scanf("%d", &newPainting.year);
    getchar();

    FILE* paintingFile = fopen("paintings.txt", "a");
    if (paintingFile == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    fprintf(paintingFile, "%s,%s,%s,%d\n", newPainting.title, newPainting.artist, newPainting.medium, newPainting.year);
    fclose(paintingFile);
    printf("Painting added to file!\n");
}

void viewPaintings() {
    FILE* paintingFile = fopen("paintings.txt", "r");
    if (paintingFile == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    printf("Title\t\tArtist\t\tMedium\t\tYear\n");
    char buffer[200];
    while (fgets(buffer, 200, paintingFile)) {
        printf("%s", buffer);
    }

    fclose(paintingFile);
}

int main() {
    int choice;
    printf("1. Create new painting file\n2. Add painting to file\n3. View paintings in file\n4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            createPaintingFile();
            break;
        case 2:
            addPainting();
            break;
        case 3:
            viewPaintings();
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}