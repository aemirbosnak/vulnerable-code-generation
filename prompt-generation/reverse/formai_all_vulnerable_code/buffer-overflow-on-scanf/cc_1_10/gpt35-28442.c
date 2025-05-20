//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_name[100], virus_signature[30] = "Antivirus123";
    int signature_length = strlen(virus_signature), is_virus = 0;
    FILE *ptr;

    printf("Enter the name of the file to scan: ");
    scanf("%s", file_name);

    ptr = fopen(file_name, "rb"); //open the file in binary mode

    if (ptr == NULL) { //if the file not found
        printf("File not found!\n");
        return 0;
    }

    char buffer[signature_length]; //buffer to store read data
    int read, i;

    while ((read = fread(buffer, sizeof(char), signature_length, ptr)) != 0) { //scan the file in chunks
        if (read == signature_length) { 
            //check if read chunk size equals to the signature size
            for (i = 0; i < signature_length; i++) {
                if (buffer[i] != virus_signature[i]) {
                    //check if the bytes in the chunk match the signature
                    is_virus = 0;
                    break;
                } else {
                    is_virus = 1;
                }
            }
            if (is_virus) {
                printf("Virus detected!\n");
                break; //exit the loop if virus detected
            }
        } else {
            break; //exit the loop if end of file reached
        }
    }

    fclose(ptr); //close the file
    if (!is_virus) {
        printf("File scanned successfully! No virus detected.\n");
    }

    return 0;
}