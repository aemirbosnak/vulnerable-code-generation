//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define WATERMARK "Watermark"
#define WATERMARK_SIZE (sizeof(WATERMARK) - 1)

// Function to embed watermark into the text
void embed_watermark(const char *input, char *output) {
    size_t input_len = strlen(input);
    size_t watermark_len = strlen(WATERMARK);

    // Check if the input can accommodate the watermark
    if (input_len + watermark_len + 1 > MAX_SIZE) {
        fprintf(stderr, "Error: Input text is too long to embed watermark.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the input text to the output
    strcpy(output, input);
    // Append the watermark
    strcat(output, WATERMARK);
}

// Function to extract watermark from the text
int extract_watermark(const char *input, char *watermark) {
    char *location = strstr(input, WATERMARK);
    if (location != NULL) {
        strcpy(watermark, WATERMARK);
        return 1; // Watermark found
    }
    return 0; // Watermark not found
}

// Function to simulate a digital watermarking process
void watermark_process(const char *input_file, const char *output_file) {
    FILE *fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Read the input file
    char input_text[MAX_SIZE];
    fread(input_text, sizeof(char), MAX_SIZE - 1, fp_in);
    input_text[MAX_SIZE - 1] = '\0'; // Null-terminate string
    fclose(fp_in);

    char output_text[MAX_SIZE];
    embed_watermark(input_text, output_text);

    // Write the output to file
    FILE *fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", output_file);
        exit(EXIT_FAILURE);
    }
    
    fwrite(output_text, sizeof(char), strlen(output_text), fp_out);
    fclose(fp_out);

    printf("Watermark embedded successfully!\n");
}

// Function to check for watermark presence in the input file
void check_watermark(const char *input_file) {
    FILE *fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Read the input file
    char input_text[MAX_SIZE];
    fread(input_text, sizeof(char), MAX_SIZE - 1, fp_in);
    input_text[MAX_SIZE - 1] = '\0'; // Null-terminate string
    fclose(fp_in);

    char extracted_watermark[WATERMARK_SIZE + 1];
    int found = extract_watermark(input_text, extracted_watermark);

    if (found) {
        printf("Watermark found: %s\n", extracted_watermark);
    } else {
        printf("No watermark detected.\n");
    }
}

// Main menu for user interaction
void menu() {
    printf("\nDigital Watermarking Tool\n");
    printf("==========================\n");
    printf("1. Embed Watermark\n");
    printf("2. Check Watermark\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];

    while(1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter input file name: ");
                scanf("%s", input_file);
                printf("Enter output file name: ");
                scanf("%s", output_file);
                watermark_process(input_file, output_file);
                break;
            case 2:
                printf("Enter input file name to check: ");
                scanf("%s", input_file);
                check_watermark(input_file);
                break;
            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}