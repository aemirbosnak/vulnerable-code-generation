//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data { //structure to store the recovered data
    unsigned char bytes[4096];
    long int length;
};

int main() {
    FILE *fp; //file pointer to retrieve lost data
    int i, j, k, l, m;
    char filename[100], ext[10];
    struct data recovered[1000]; //array of recovered data
    int count = 0; //count of recovered files
    long int fsize;
    unsigned char buffer[4096];
    
    printf("Enter the file name: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "rb");
    
    if(fp == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    for(i=0; i<fsize; i++) {
        fread(buffer, 1, 4, fp); //read first 4 bytes of every 4096 bytes
        
        if(buffer[0] == 'P' && buffer[1] == 'K' && buffer[2] == 0x03 && buffer[3] == 0x04) { //check for PK signature of a zip file
            
            long int current_pos = ftell(fp);
            fseek(fp, current_pos-4, SEEK_SET); //go back to start of PK signature
            fread(buffer, 1, 30, fp); //read first 30 bytes of zip file header
            
            for(j=0; j<26; j++) {
                if(buffer[j] == '.') {
                    for(k=0; k<3; k++) {
                        ext[k] = buffer[j+k+1];
                    }
                    ext[3] = '\0';
                    break;
                }
            }
            
            fseek(fp, current_pos-4, SEEK_SET); //go back to start of PK signature
            fread(buffer, 1, 4096, fp); //read the entire zip file
            
            for(l=0; l<4096; l++) {
                if(buffer[l] == 'P' && buffer[l+1] == 'K' && buffer[l+2] == 0x05 && buffer[l+3] == 0x06) { //check for PK signature of a directory in zip file
                    
                    long int file_start = l+30; //start of file name in header
                    long int file_end = l+30; //end of file name in header
                    
                    while(buffer[file_end] != 0x0A) { //find end of filename
                        file_end++;
                    }
                    
                    file_end -= 2; //remove last \r
                    
                    long int file_size_start = file_end+1; //start of file size in header
                    long int file_size_end = file_size_start; //end of file size in header
                    
                    while(buffer[file_size_end] != 0x0A) { //find end of file size
                        file_size_end++;
                    }
                    
                    file_size_end -= 2; //remove last \r
                    
                    long int file_data_start = file_size_end+2; //start of file data in buffer
                    long int file_data_end = file_data_start + strtol((char *)&buffer[file_size_start], NULL, 10); //end of file data in buffer
                    
                    struct data d; //create new struct for this recovered file
                    
                    d.length = file_data_end - file_data_start; //store the length of the file data
                    
                    for(m=0; m<d.length; m++) {
                        d.bytes[m] = buffer[file_data_start+m]; //store the file data in the struct
                    }
                    
                    recovered[count] = d; //store the struct in the array of recovered data
                    count++; //increment the count of recovered files
                }
            }
        }
        
        fseek(fp, i+4096, SEEK_SET); //skip to the next 4096 bytes
    }
    
    fclose(fp); //close the file
    
    printf("Recovered files:\n\n");
    for(i=0; i<count; i++) {
        char new_filename[100];
        sprintf(new_filename, "%d.%s", i+1, ext);
        FILE *new_fp = fopen(new_filename, "wb");
        fwrite(recovered[i].bytes, 1, recovered[i].length, new_fp);
        fclose(new_fp);
        printf("%s\n", new_filename);
    }
    
    return 0;
}