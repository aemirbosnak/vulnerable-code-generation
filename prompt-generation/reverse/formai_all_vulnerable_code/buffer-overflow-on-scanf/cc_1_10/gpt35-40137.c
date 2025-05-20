//FormAI DATASET v1.0 Category: Data recovery tool ; Style: excited
// Hey all data-recovery enthusiasts, welcome to the amazing world of C Data Recovery Tool!
// This program is going to be a game changer in the world of data recovery. Sit tight and enjoy the magic!

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {

    printf("Let's recover some lost data!\n");
    printf("Enter the name of the file to recover: ");

    // getting the filename from the user and opening it
    char filename[50];
    scanf("%s", filename);

    FILE* fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error: File Not Found!\n");
        return 1;
    }

    // creating a new file to which data will be recovered
    char recovered_filepath[50];
    strcpy(recovered_filepath, "recovered_");
    strcat(recovered_filepath, filename);

    FILE* fw = fopen(recovered_filepath, "wb");

    // fetching the size of the file to be recovered
    fseek(fp, 0L, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // creating a buffer with the same size as that of the file
    char* buffer = (char*)malloc(file_size);

    // reading the contents of the file to the buffer
    fread(buffer, file_size, 1, fp);

    // writing the buffer contents to the new file
    fwrite(buffer, file_size, 1, fw);

    // closing the file pointers and freeing the buffer memory
    fclose(fp);
    fclose(fw);
    free(buffer);

    printf("Data recovered successfully!\n");

    return 0;
}