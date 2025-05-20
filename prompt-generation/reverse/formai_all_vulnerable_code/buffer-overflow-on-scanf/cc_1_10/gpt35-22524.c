//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This antivirus scanner scans a file for some signature virus patterns. 
If any pattern is found, the infected file is quarantined and removed from the system.*/

int main(){

    char filename[100];
    char virus_signature[] = "2F44E08C051E37F27E4EAA62C65EF9CF"; //MD5 hash of known virus signature

    printf("Welcome to our C Antivirus Scanner.\n");
    printf("Enter the file name to scan: ");
    scanf("%s", filename);

    FILE *file_to_scan;
    file_to_scan = fopen(filename, "r");

    if (file_to_scan == NULL) {
        printf("Error opening file! Please provide a valid file name.\n");
        return 0;
    }

    printf("Scanning file....\n");

    // Get the file size by jumping to the end of file and returning to the beginning
    fseek(file_to_scan, 0, SEEK_END);
    long file_size = ftell(file_to_scan);
    fseek(file_to_scan, 0, SEEK_SET);

    char *file_contents = (char *)malloc(file_size + 1);
    fread(file_contents, file_size, 1, file_to_scan);
    fclose(file_to_scan);

    file_contents[file_size] = 0; // terminate the string with null character

    // Calculate the MD5 hash of the file contents
    unsigned char md5_hash[16];
    MD5(file_contents, strlen(file_contents), md5_hash);

    char signature[33]; //store the md5 hash as a string
    int i;
    for(i=0; i<16; i++){
        sprintf(signature+(i*2), "%02x", md5_hash[i]);
    }
      
    // compare the md5 hash with the virus_signature to determine if file is infected or not
    if (strcmp(virus_signature, signature) == 0){
         printf("Virus detected! Quarantining file...");
         remove(filename); //remove the infected file from the system
         printf("File was removed from the system.\n");
    }
    
    else{
        printf("File is clean. No virus detected.\n");
    }

    return 0; 
}