//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define MAX_DATA_SIZE 1024

// Function to read data from a file
int read_data_from_file(FILE *fp, char data[]){
    int i=0, ch;
    while((ch = fgetc(fp)) != EOF){
        data[i] = ch;
        i++;
    }
    data[i] = '\0';
    return i; // returns the length of data
}

// Function to recover the deleted data
char* data_recovery_tool(char file_name[]){

    // Open the file in binary mode
    FILE *fp = fopen(file_name, "rb");
    if(fp == NULL){
        printf("Error: File cannot be opened.\n");
        exit(1);
    }

    // Read the data from file into a buffer
    char data[MAX_DATA_SIZE];
    int data_len = read_data_from_file(fp, data);
    fclose(fp);

    // Recover the data by removing the last 4 bytes (if present)
    if(data[data_len-1] == '\n'){
        data[data_len-1] = '\0';
        data_len--;
    }
    if(data[data_len-1] == '\r'){
        data[data_len-1] = '\0';
        data_len--;
    }
    if(data[data_len-1] == 0x1A){
        data[data_len-1] = '\0';
        data_len--;
    }
    if(data[data_len-1] == 0x00){
        data[data_len-1] = '\0';
        data_len--;
    }

    // Allocate memory to store the recovered data
    char *recovered_data = (char*)calloc(data_len+1, sizeof(char)); 
    if(recovered_data == NULL){
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    // Copy the data to the new memory location
    strcpy(recovered_data, data);
    return recovered_data;
}

int main(){
    char file_name[] = "deleted_file.bin";
    char *recovered_data = data_recovery_tool(file_name);

    printf("Recovered Data: %s\n", recovered_data);
    free(recovered_data);
    
    return 0;
}