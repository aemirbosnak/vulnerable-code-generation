//FormAI DATASET v1.0 Category: Data recovery tool ; Style: active
#include<stdio.h>
#include<string.h>

//Function to recover data from a damaged file
void recoverData(char fileName[]) {
    FILE *fp; //file pointer
    char ch;
    int i=0, count=0, j=0, fileSize=0; //counters and file size
    char buffer[100000], recoveredData[100000]; //buffers to store data
    
    //open the file in binary mode
    fp = fopen(fileName, "rb");
    
    if(fp == NULL) { //file not found
        printf("File not found!");
        return;
    }
    
    //calculate the file size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    //read data from the file
    while(fread(&ch, sizeof(char), 1, fp)) {
        buffer[count] = ch;
        count++;
    }
    
    //close the file
    fclose(fp);
    
    //recovery process
    while(i < fileSize) {
        if(buffer[i] == '@' && buffer[i+1] == '#' && buffer[i+2] == '$') {
            i += 3; //skip the magic marker
            
            j = 0;
            while(buffer[i] != '#' && buffer[i+1] != '@' && buffer[i+2] != '$') {
                recoveredData[j] = buffer[i];
                i++;
                j++;
            }
            recoveredData[j] = '\0';
            
            printf("%s", recoveredData); //print the recovered data
        }
        i++;
    }
}

int main() {
    char fileName[100];
    
    printf("Enter the file name: ");
    gets(fileName);
    
    recoverData(fileName); //call the recoverData function
    
    return 0;
}