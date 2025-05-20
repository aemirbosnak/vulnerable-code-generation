//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define a structure to hold metadata information */
struct meta_data {
    char title[100];
    char artist[100];
    char album[100];
    char year[5];
};

/* Declare a function to extract metadata */
void extract_metadata(char *filename) {

    /* Open the file in read mode */
    FILE *fp;
    fp = fopen(filename, "r");

    /* Check if the file exists */
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }

    /* Allocate memory for meta_data structure */
    struct meta_data *metadata = (struct meta_data *)malloc(sizeof(struct meta_data));

    /* Read the first line of the file */
    char buffer[1000];
    fgets(buffer, sizeof(buffer), fp);

    /* Extract metadata information from the first line */
    char *token;
    token = strtok(buffer, "|");
    strcpy(metadata->title, token);
    token = strtok(NULL, "|");
    strcpy(metadata->artist, token);
    token = strtok(NULL, "|");
    strcpy(metadata->album, token);
    token = strtok(NULL, "|");
    strcpy(metadata->year, token);

    /* Print the extracted metadata */
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %s\n", metadata->year);

    /* Free the allocated memory */
    free(metadata);

    /* Close the file */
    fclose(fp);
}

int main() {
    char filename[100];

    /* Get the filename from user */
    printf("Enter the filename: ");
    scanf("%s", filename);

    /* Call the extract_metadata function */
    extract_metadata(filename);

    return 0;
}