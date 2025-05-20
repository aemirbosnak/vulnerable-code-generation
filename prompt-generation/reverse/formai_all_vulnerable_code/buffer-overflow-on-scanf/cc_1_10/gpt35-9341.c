//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Define the struct for the surreal file.
typedef struct {
    char name[20];
    char extension[10];
    int size;
} surreal_file;

int main(){
    srand(time(NULL)); // Initialize the random seed.
    
    surreal_file f1; // Declare a surreal file.
    
    // Add some surreal value to the name of the file.
    printf("Enter the name of the file: ");
    scanf("%s", f1.name);
    strcat(f1.name, "_surreal");
    
    // Add some surreal value to the extension of the file.
    printf("Enter the extension of the file: ");
    scanf("%s", f1.extension);
    if(strlen(f1.extension) > 3){
        printf("Invalid extension. Using default extension .txt\n");
        strcpy(f1.extension, "txt");
    }
    strcat(f1.extension, "_dream");
    
    // Generate some surreal value for the size of the file.
    f1.size = rand() % 10000;
    
    // Create the file and write the surreal values inside.
    FILE *fp;
    fp = fopen(strcat(f1.name, "."), f1.extension);
    
    if(fp){
        fprintf(fp, "Name: %s\nExtension: %s\nSize: %d bytes\nContent: ", f1.name, f1.extension, f1.size);
        
        for(int i=0; i<f1.size; i++){
            fprintf(fp, "%c", (char)(rand() % 94 + 32));
        }
        
        printf("File created successfully\n");
    }
    else{
        printf("Failed to create file\n");
    }
    
    fclose(fp); // Close the file.
    
    return 0;
}