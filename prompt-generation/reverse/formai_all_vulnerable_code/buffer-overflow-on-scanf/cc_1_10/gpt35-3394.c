//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 10 // Define the size of the watermark

// Function to print the watermark
void printWatermark(char * watermark){
    printf("\nWatermark: ");
    for(int i = 0; i < WATERMARK_SIZE; i++){
        printf("%c", watermark[i]); // Print each character of the watermark
    }
    printf("\n");
}

int main(){
    char originalText[100]; // Define a character array to store the original text
    char watermark[WATERMARK_SIZE]; // Define a character array to store the watermark
    printf("Enter the original text: ");
    scanf("%[^\n]s", originalText); // Read the original text until a newline character is found

    printf("Enter the watermark: ");
    scanf("%s", watermark); // Read the watermark

    printWatermark(watermark); // Print the watermark

    // Embed the watermark into the original text
    int textLength = strlen(originalText);
    int counter = 0;
    for(int i = 0; i < textLength; i++){
        if(counter < WATERMARK_SIZE){
            originalText[i] = watermark[counter];
            counter++;
        } else {
            counter = 0; // Reset the counter to start embedding the watermark again
        }
    }

    printf("Text with watermark: %s\n", originalText); // Print the text with the watermark

    // Retrieve the watermark from the watermarked text
    char retrievedWatermark[WATERMARK_SIZE];
    counter = 0;
    for(int i = 0; i < textLength; i++){
        if(counter < WATERMARK_SIZE){
            retrievedWatermark[counter] = originalText[i];
            counter++;
        } else {
            counter = 0; // Reset the counter to start retrieving the watermark again
        }
    }

    printWatermark(retrievedWatermark); // Print the retrieved watermark

    return 0;
}