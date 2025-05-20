//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
} Image;

void displayWelcomeMessage() {
    printf("Welcome, dear coder, to the realm of Image Classification!\n");
    printf("Here, we shall classify images that speak the language of love.\n\n");
}

void addImage(Image images[], int *count) {
    if (*count >= MAX_IMAGES) {
        printf("The heart is too full; cannot add more images!\n");
        return;
    }
    
    printf("Enter the name of the image (filename): ");
    scanf("%s", images[*count].name);
    
    printf("Define the category of this image (e.g., Love, Joy, Sadness): ");
    scanf("%s", images[*count].category);
    
    printf("Ah, the image %s has been captured in the category of %s!\n\n", 
           images[*count].name, images[*count].category);
    
    (*count)++;
}

void viewImages(Image images[], int count) {
    printf("Here lies the gallery of emotions:\n");
    for (int i = 0; i < count; i++) {
        printf("Image: %s, Category: %s\n", images[i].name, images[i].category);
    }
    printf("\n");
}

void classifyImages(Image images[], int count) {
    char searchCategory[MAX_CATEGORY_LENGTH];
    printf("Whisper the category you seek (e.g., Love, Joy, Sadness): ");
    scanf("%s", searchCategory);
    
    printf("Searching for images that echo the harmony of %s...\n", searchCategory);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(images[i].category, searchCategory) == 0) {
            printf("Image: %s, Category: %s\n", images[i].name, images[i].category);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Alas, no images reflect the beauty of %s in our collection.\n\n", searchCategory);
    } else {
        printf("\nPresence of memories in the category %s is a sweet joy!\n", searchCategory);
    }
}

int main() {
    Image images[MAX_IMAGES];
    int imageCount = 0;
    int choice;
    
    displayWelcomeMessage();
    
    while (1) {
        printf("Choose your path:\n");
        printf("1. Add an Image\n");
        printf("2. View All Images\n");
        printf("3. Classify Images by Category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addImage(images, &imageCount);
                break;
            case 2:
                viewImages(images, imageCount);
                break;
            case 3:
                classifyImages(images, imageCount);
                break;
            case 4:
                printf("Farewell, sweet coder! May your heart remain light and bright!\n");
                exit(0);
            default:
                printf("A curious choice, but alas, it’s not on our menu of love.\n");
                break;
        }
    }
    
    return 0;
}