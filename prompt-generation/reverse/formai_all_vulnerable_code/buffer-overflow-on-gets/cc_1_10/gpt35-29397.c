//FormAI DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include<stdio.h>
#include<string.h>

//Function to remove extra spaces and tabs from the string
char* removeSpaces(char* str){
    int i,j;
    for(i=0,j=0;str[i];i++){
        if(str[i] != ' ' && str[i] != '\t')
            str[j++] = str[i];
    }
    str[j] = '\0';
    return str;
}

// Function to beautify HTML code 
void beautifyCode(char* code){
    // initializing strings for open/close tags
    char open_tag[50], close_tag[50];
    int tabSpace = 0;

    //split the code by newline
    char *line = strtok(code, "\n");

    //iterate until the end of string
    while(line){
        //Removing extra spaces and tabs
        removeSpaces(line);

        //If starting tag
        if(line[0] == '<' && line[1] != '/'){
            //Adding tab for nested tags
            for(int i=0;i<tabSpace;i++)
                printf("\t");
            //Printing opening tag
            printf("%s",line);

            //Extracting tag name
            int i=0;
            while(line[i] != ' ' && line[i] != '>'){
                open_tag[i] = line[i];
                i++;
            }
            
            open_tag[i] = '\0';

            printf("\n");
            tabSpace++;
        }
        //If ending tag
        else if(line[0] == '<' && line[1] == '/'){
            //Removing one tab space for nested tags
            tabSpace--;
            for(int i=0;i<tabSpace;i++)
                printf("\t");

            //Printing closing tag
            printf("%s",line);

            //Extracting tag name
            int i=0;
            while(line[i] != '>'){
                close_tag[i] = line[i];
                i++;
            }
            
            close_tag[i] = '\0';

            //Matching opening and closing tags
            if(strcmp(open_tag,close_tag) != 0){
                printf("\tTags Mismatched");
                return;
            }
            printf("\n");
        }
        //If content inside tags
        else{
            for(int i=0;i<tabSpace;i++)
                printf("\t");
            printf("%s\n",line);
        }

        //Move to next line
        line = strtok(NULL, "\n");
    }

    //Check if all tags are ended properly
    if(tabSpace != 0)
        printf("\tIncomplete HTML Code");
}

int main(){
    char html_code[1000];
    printf("Enter the HTML code:\n");
    gets(html_code);

    printf("\n\nBeautified Code:\n");
    beautifyCode(html_code);
    
    return 0;
}