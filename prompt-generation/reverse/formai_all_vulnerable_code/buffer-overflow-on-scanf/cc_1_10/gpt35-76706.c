//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp1, *fp2;
    char filename[100], ch;

    // Open the file to be formatted
    printf("Enter the file name to be formatted:\n");
    scanf("%s", filename);

    fp1 = fopen(filename, "r+");
    if(fp1 == NULL){
        printf("%s file does not exist!\n", filename);
        exit(0);
    }

    // Open a new file to hold the formatted code
    fp2 = fopen("formatted.html", "w+");
    if(fp2 == NULL){
        printf("Error creating the formatted file!\n");
        exit(0);
    }

    int indent = 0;
    while((ch = fgetc(fp1)) != EOF){
        if(ch == '<'){
            fputc(ch, fp2);
            if(fgetc(fp1) != '/'){
                fputc('\n', fp2);
                for(int i = 0; i < indent; i++){
                    fputc('\t', fp2);
                }
                indent++;
            }
            else{
                indent--;
                fputc('\n', fp2);
                for(int i = 0; i < indent; i++){
                    fputc('\t', fp2);
                }
            }
        }
        else if(ch == '>'){
            fputc(ch, fp2);
            fputc('\n', fp2);
            for(int i = 0; i < indent; i++){
                fputc('\t', fp2);
            }
        }
        else{
            fputc(ch ,fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("File formatted successfully!\n");

    return 0;
}