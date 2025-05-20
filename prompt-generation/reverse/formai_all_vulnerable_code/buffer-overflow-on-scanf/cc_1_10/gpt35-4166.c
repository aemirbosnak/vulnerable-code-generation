//FormAI DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include<stdio.h> 

int main() { 

    //Variables to store the HTML file
    char html_file[100];
    char beautified_file[100];
    FILE *fp1, *fp2;
    
    //Opening Input HTML File
    printf("Enter the name of the HTML file: ");
    scanf("%s", html_file);
    fp1 = fopen(html_file, "r");
    if(fp1 == NULL) {
        printf("Cannot open HTML file!");
        return 0;
    }
    
    //Opening Output Beautified HTML File
    printf("Enter the name of the beautified HTML file: ");
    scanf("%s", beautified_file);
    fp2 = fopen(beautified_file, "w");
    
    //Beautifying the HTML File
    int indent_level = 0;
    char ch;
    while((ch = fgetc(fp1)) != EOF) {
        switch(ch) {
            case '<':
                fputc('\n', fp2);
                for(int i=0;i<indent_level;i++)
                    fputc('\t', fp2);
                fputc(ch, fp2);
                indent_level++;
                break;
            case '>':
                fputc(ch, fp2);
                break;
            case '/':
                indent_level--;
                fputc(ch, fp2);
                break;
            default:
                fputc(ch, fp2);
                break;
        }
    }
    
    //Closing both files
    fclose(fp1);
    fclose(fp2);
    
    //Successful completion of program
    printf("HTML file successfully beautified!\n");
    return 0;
}