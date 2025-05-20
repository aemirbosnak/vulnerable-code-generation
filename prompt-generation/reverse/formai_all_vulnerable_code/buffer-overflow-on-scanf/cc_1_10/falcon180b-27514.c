//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1000000 // maximum size of the image
#define MAX_HIDDEN_SIZE 500000 // maximum size of the hidden data

// Function to generate a random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to hide the data in the image
void hideData(char* image, char* data) {
    int i = 0, j = 0;
    while (i < strlen(image) && j < strlen(data)) {
        if (isalpha(image[i]) && isalpha(data[j])) {
            int k = randInt(0, 2);
            if (k == 0) {
                image[i] = toupper(image[i]);
            } else if (k == 1) {
                image[i] = tolower(image[i]);
            } else {
                image[i] = data[j];
            }
            i++;
            j++;
        } else {
            i++;
        }
    }
}

// Function to extract the hidden data from the image
char* extractData(char* image) {
    int i = 0, j = 0;
    char* data = malloc(MAX_HIDDEN_SIZE * sizeof(char));
    while (i < strlen(image) && j < MAX_HIDDEN_SIZE) {
        if (isalpha(image[i])) {
            data[j] = image[i];
            j++;
        }
        i++;
    }
    data[j] = '\0';
    return data;
}

int main() {
    srand(time(NULL)); // initialize random seed
    char* image = malloc(MAX_SIZE * sizeof(char));
    char* data = malloc(MAX_HIDDEN_SIZE * sizeof(char));

    printf("Enter the image file name: ");
    scanf("%s", image);

    printf("Enter the data to be hidden: ");
    scanf("%s", data);

    hideData(image, data);

    printf("Image with hidden data:\n%s\n", image);

    char* extractedData = extractData(image);
    printf("Extracted data: %s\n", extractedData);

    free(image);
    free(data);
    free(extractedData);

    return 0;
}