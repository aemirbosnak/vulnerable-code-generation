//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define ebook struct
typedef struct{
    char* title;
    char* author;
    int length;
    char* content;
} Ebook;

// Prototype functions
void print_ebook(Ebook* book);
int read_ebook(char* filename, Ebook* book);

int main(){
    srand(time(NULL)); // Set random seed

    // Create ebook object
    Ebook book;

    // Get filename from user
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Read ebook from file
    int success = read_ebook(filename, &book);

    // Print ebook if read successful
    if(success){
        print_ebook(&book);

        // Randomly generate a quote from the ebook
        int rand_pos = rand() % book.length;
        int quote_length;
        for(int i=rand_pos; i<book.length; i++){
            if(book.content[i] == '.' || book.content[i] == '?' || book.content[i] == '!'){
                quote_length = i - rand_pos + 1;
                break;
            }
        }
        char quote[quote_length+1];
        strncpy(quote, book.content+rand_pos, quote_length);
        quote[quote_length] = '\0';

        // Print quote
        printf("Random Quote: %s\n", quote);
    }
    else{
        printf("Error reading ebook from file!\n");
    }

    return 0;
}

// Function to read ebook from file
int read_ebook(char* filename, Ebook* book){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        return 0;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    // Read title and author from file
    char title[100];
    char author[100];
    fscanf(file, "%s %s\n", title, author);

    // Allocate memory for title and author
    book->title = (char*) malloc(strlen(title)+1);
    book->author = (char*) malloc(strlen(author)+1);

    // Copy title and author to ebook object
    strcpy(book->title, title);
    strcpy(book->author, author);

    // Allocate memory for content
    book->content = (char*) malloc(file_size);

    // Read content from file
    int i = 0;
    char c;
    while((c = fgetc(file)) != EOF){
        book->content[i] = c;
        i++;
    }

    // Set length of ebook
    book->length = i;

    fclose(file);
    return 1;
}

// Function to print ebook
void print_ebook(Ebook* book){
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Length: %d\n", book->length);
}