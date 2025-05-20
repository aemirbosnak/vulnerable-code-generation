//FormAI DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

//declare a struct to store file information
struct file{
    char name[50];
    int size;
    char data[1000];
};

int main(){
    //initialize variables
    int choice, num_files;
    FILE *fp;
    struct file *files;

    //prompt user for number of files to recover
    printf("How many files would you like to recover?\n");
    scanf("%d", &num_files);
    getchar();

    //allocate memory for file structs
    files = (struct file*) malloc(num_files * sizeof(struct file));

    //loop through each file and prompt user for file name
    for(int i=0; i<num_files; i++){
        printf("Enter file name for file #%d:\n", i+1);
        fgets(files[i].name, 50, stdin);
        //remove newline character at end of input
        files[i].name[strcspn(files[i].name, "\n")] = 0;
        //open file for reading
        fp = fopen(files[i].name, "r");
        //if file exists, read in file size and data
        if(fp){
            //get file size
            fseek(fp, 0L, SEEK_END);
            files[i].size = ftell(fp);
            rewind(fp);
            //read in file data
            fread(files[i].data, sizeof(char), files[i].size, fp);
            //close file
            fclose(fp);
        }
        //if file does not exist, notify user
        else{
            printf("Can't open file '%s', file will be skipped.\n", files[i].name);
        }
    }

    //print recovered files
    printf("\nRecovered files:\n");
    for(int i=0; i<num_files; i++){
        //if file was successfully recovered, print file name and size
        if(files[i].size>0){
            printf("%s (%d bytes)\n", files[i].name, files[i].size);
        }
    }

    //free memory
    free(files);

    //exit program
    return 0;
}