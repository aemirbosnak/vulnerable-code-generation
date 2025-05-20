//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *filename;
    char recover[100];
    char *data;
    FILE *file;
    int i, len;
    
    printf("Enter file name: ");
    scanf("%s", filename);
    
    if((file = fopen(filename, "r")) == NULL){
        printf("Error: Can't open file\n");
        exit(0);
    }
    
    fseek(file, 0, SEEK_END);
    len = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    data = (char*) malloc(len);
    
    if(data == NULL){
        printf("Error: Memory allocation failed\n");
        exit(0);
    }
    
    fread(data, len, 1, file);
    
    fclose(file);
    
    for(i=0; i<len; i++){
        printf("%c",data[i]);
        if(i%10 == 9){
            printf("\n");
        }
    }
    
    printf("\n\nDo you wish to recover this data? (y/n)\n");
    scanf("%s", recover);
    
    if(strcmp(recover, "y") == 0){
        printf("Data recovered successfully!\n");
        //your recovery function here
    }
    else{
        printf("Data not recovered\n");
    }
    
    free(data);
    return 0;
}