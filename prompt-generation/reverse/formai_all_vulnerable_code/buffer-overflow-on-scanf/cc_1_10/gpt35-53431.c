//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
// C Metadata Extractor Example Program
// By MathBot
// Dated: 01/01/2022

#include <stdio.h>

// Structures for various metadata types
struct mp3_metadata {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

struct jpeg_metadata {
    int width;
    int height;
    char camera_make[20];
    char camera_model[20];
};

struct docx_metadata {
    char author[50];
    char title[50];
    int word_count;
};

int main() {
    // Example MP3 metadata extraction
    struct mp3_metadata my_mp3;
    printf("Enter MP3 title: ");
    scanf("%s", my_mp3.title);
    printf("Enter artist: ");
    scanf("%s", my_mp3.artist);
    printf("Enter album: ");
    scanf("%s", my_mp3.album);
    printf("Enter year: ");
    scanf("%d", &my_mp3.year);
    
    printf("\nMP3 Metadata:\n");
    printf("Title: %s\n", my_mp3.title);
    printf("Artist: %s\n", my_mp3.artist);
    printf("Album: %s\n", my_mp3.album);
    printf("Year: %d\n", my_mp3.year);
    
    // Example JPEG metadata extraction
    struct jpeg_metadata my_jpeg;
    printf("\n\nEnter JPEG width: ");
    scanf("%d", &my_jpeg.width);
    printf("Enter JPEG height: ");
    scanf("%d", &my_jpeg.height);
    printf("Enter camera make: ");
    scanf("%s", my_jpeg.camera_make);
    printf("Enter camera model: ");
    scanf("%s", my_jpeg.camera_model);
    
    printf("\nJPEG Metadata:\n");
    printf("Width: %d\n", my_jpeg.width);
    printf("Height: %d\n", my_jpeg.height);
    printf("Camera Make: %s\n", my_jpeg.camera_make);
    printf("Camera Model: %s\n", my_jpeg.camera_model);
    
    // Example DOCX metadata extraction
    struct docx_metadata my_docx;
    printf("\n\nEnter author: ");
    scanf("%s", my_docx.author);
    printf("Enter title: ");
    scanf("%s", my_docx.title);
    printf("Enter word count: ");
    scanf("%d", &my_docx.word_count);
    
    printf("\nDOCX Metadata:\n");
    printf("Author: %s\n", my_docx.author);
    printf("Title: %s\n", my_docx.title);
    printf("Word Count: %d\n", my_docx.word_count);
    
    return 0;
}