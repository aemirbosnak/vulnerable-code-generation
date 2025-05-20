//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for the recovered data
typedef struct Data {
    char* name;
    char* content;
} Data;

// function to recover data from file
Data* recover_data(char* filename) {
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return NULL;
    }
    
    // determine file size
    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    // allocate memory for data
    Data* data = malloc(sizeof(Data));
    data->name = filename;
    data->content = malloc(sizeof(char) * (size + 1));
    
    // read data from file
    fread(data->content, sizeof(char), size, file);
    data->content[size] = '\0';
    
    fclose(file);
    return data;
}

int main() {
    char filename[256];
    printf("Enter the filename to recover data: ");
    scanf("%s", filename);
    
    Data* recovered_data = recover_data(filename);
    
    if(recovered_data == NULL) {
        printf("Data recovery failed.\n");
    } else {
        printf("Data recovered successfully from file '%s'.\n", recovered_data->name);
        printf("Content:\n%s", recovered_data->content);
        
        // free memory
        free(recovered_data->name);
        free(recovered_data->content);
        free(recovered_data);
    }
    
    return 0;
}