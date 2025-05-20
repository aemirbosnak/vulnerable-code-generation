//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-style ASCII art
char *art =
"________________________________________________________________________________________________________________________________________________________________________________________________________\n"
"|                                                                                                                                                                                                      |\n"
"|              _.._                                                                                                                                                                                                   |\n"
"|         .+@   @+.                                                                                                                                                                                                  |\n"
"|       .@^o;_.---.._                                                                                                                                                                                               |\n"
"|      @+o@@.           @@+-                                                                                                                                                                                           |\n"
"|      @+@o@            @o@@                                                                                                                                                                                          |\n"
"|      @+@@o_       __  @o@@                                                                                                                                                                                          |\n"
"|      @+@o@@+`~----'~+@@@+                                                                                                                                                                                          |\n"
"|      @+o@@@@@.               `@o@@@+-                                                                                                                                                                               |\n"
"|      o@#@@.               .  `@@@@@+                                                                                                                                                                           |\n"
"|      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+                                                                                                                                                                      |\n"
"|     `@@@@@@@\0\0\0\0\0\0\0\0\0\0\0/@@@@@@@'                                                                                                                                                                    |\n"
"|         `@;    :# =###=#%    ;@'                                                                                                                                                                        |\n"
"|            `#   :# :###::   #'                                                                                                                                                                           |\n"
"|               @  :# :###==  @                                                                                                                                                                               |\n"
"|                  # #.::####. #                                                                                                                                                                                  |\n"
"|                     #### ####                                                                                                                                                                                     |\n"
"|                           ###  ###                                                                                                                                                                                     |\n"
"|                              ## ##                                                                                                                                                                                      |\n"
"|                                `'                                                                                                                                                                                         |\n"
"|______________________________________________________________________________________________________________________________________________________________________________________________________|\n";

// Function to embed a watermark in an image
void embed_watermark(unsigned char *image, int width, int height, char *watermark)
{
    // Get the length of the watermark
    int watermark_len = strlen(watermark);

    // Embed the watermark in the image's least significant bits
    for (int i = 0; i < watermark_len; i++)
    {
        // Get the ASCII value of the watermark character
        int watermark_char = watermark[i];

        // Get the least significant bit of the watermark character
        int watermark_bit = watermark_char & 0x01;

        // Set the least significant bit of the image pixel to the watermark bit
        image[i] = (image[i] & 0xfe) | watermark_bit;
    }
}

// Function to extract a watermark from an image
char *extract_watermark(unsigned char *image, int width, int height)
{
    // Allocate memory for the watermark
    char *watermark = malloc(width * height);

    // Extract the watermark from the image's least significant bits
    for (int i = 0; i < width * height; i++)
    {
        // Get the least significant bit of the image pixel
        int watermark_bit = image[i] & 0x01;

        // Set the watermark character to the corresponding ASCII value
        watermark[i] = watermark_bit ? '1' : '0';
    }

    // Return the watermark
    return watermark;
}

// Main function
int main()
{
    // Display the Cyberpunk-style ASCII art
    printf("%s", art);

    // Get the image filename from the user
    char *image_filename = "image.bmp";

    // Load the image from disk
    FILE *image_file = fopen(image_filename, "rb");
    if (image_file == NULL)
    {
        printf("Error opening image file: %s\n", image_filename);
        return 1;
    }

    // Get the image width and height
    int width, height;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height);

    // Read the image data from disk
    fread(image, sizeof(unsigned char), width * height, image_file);

    // Close the image file
    fclose(image_file);

    // Get the watermark from the user
    char *watermark = "Cyberpunk 2077";

    // Embed the watermark in the image
    embed_watermark(image, width, height, watermark);

    // Save the watermarked image to disk
    FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
    fwrite(&width, sizeof(int), 1, watermarked_image_file);
    fwrite(&height, sizeof(int), 1, watermarked_image_file);
    fwrite(image, sizeof(unsigned char), width * height, watermarked_image_file);
    fclose(watermarked_image_file);

    // Extract the watermark from the watermarked image
    char *extracted_watermark = extract_watermark(image, width, height);

    // Print the extracted watermark
    printf("Extracted watermark: %s\n", extracted_watermark);

    // Free the allocated memory
    free(image);
    free(extracted_watermark);

    return 0;
}