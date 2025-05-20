//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a global variable to store the watermark string
char *watermark;

// Function to recursively embed the watermark
void embed_watermark(char *message, int index, int watermark_index, int watermark_size, int message_size)
{
    // Check if we have embedded the entire watermark
    if(watermark_index == watermark_size)
        return;
        
    // Check if we have reached the end of the message string
    if(index == message_size)
        return;
        
    // Embed the current character in the watermark if it's not space or newline
    if(message[index] != ' ' && message[index] != '\n')
    {
        watermark[watermark_index] = message[index];
        watermark_index++;
    }
    
    // Recursively call the function for the next character in the message
    embed_watermark(message, index+1, watermark_index, watermark_size, message_size);
}

int main()
{
    // Define variables to store user input and file operations
    char message[1000], filename[20], ch;
    FILE *fp;
    int i, watermark_size, message_size;
    
    // Get user input for message and watermark
    printf("Enter message to embed watermark: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter watermark: ");
    scanf("%s", watermark);
    
    // Get the size of the watermark and message
    watermark_size = strlen(watermark);
    message_size = strlen(message);
    
    // Allocate memory for the watermark
    watermark = (char*) malloc(watermark_size * sizeof(char));
    
    // Call function to recursively embed the watermark
    embed_watermark(message, 0, 0, watermark_size, message_size);
    
    // Get user input for filename to save the watermarked message
    printf("Enter filename to save watermarked message: ");
    scanf("%s", filename);
    
    // Open the file in write mode
    fp = fopen(filename, "w");
    
    // Write the watermarked message to the file
    for(i=0; i<message_size; i++)
    {
        ch = message[i];
        
        // Check if the current character is a space or newline
        if(ch == ' ' || ch == '\n')
            fputc(ch, fp);
        else
        {
            // Check if the watermark is not fully embedded
            if(i < watermark_size)
                ch = watermark[i];
            fputc(ch, fp);
        }
    }
    
    // Close the file and free the memory allocated for watermark
    fclose(fp);
    free(watermark);
    
    printf("Watermark embedded successfully!\n");
    
    return 0;
}