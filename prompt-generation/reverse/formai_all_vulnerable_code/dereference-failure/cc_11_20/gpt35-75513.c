//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() 
{
    char html[10000];
    int i = 0, j = 0, tabs = 0, space = 0;
    printf("Enter the HTML code: \n");
    fgets(html,10000,stdin);
    char *clean_html = (char*)malloc(strlen(html));
    strcpy(clean_html, "");
    while(html[i]!='\0')
    {
        if(html[i] == '{' || html[i] == '(' || html[i] == '[') 
        {
            tabs+=2;
            strcat(clean_html, "    ");
            j+=4;
            clean_html[j++] = html[i++];
            clean_html[j] = '\0';
            strcat(clean_html, "\n");
            for (space = 0; space < tabs; space++) 
                strcat(clean_html, " ");
         }
         else if(html[i] == '}' || html[i] == ')' || html[i] == ']') 
         {
             tabs-=2;
             clean_html[j++] = '\n';
             for(space = 0; space < tabs; space++) 
                 strcat(clean_html, " ");
             clean_html[j++] = html[i++];
             clean_html[j] = '\0';
             if(html[i] == ',' || html[i] == ';')
             {
                 clean_html[j++] = html[i++];
                 clean_html[j++] = '\n';
                 clean_html[j] = '\0';
                 for (space = 0; space < tabs; space++) 
                    strcat(clean_html, " ");
             }
         }
         else if(html[i] == ',' || html[i] == ';') 
         {
             clean_html[j++] = html[i++];
             clean_html[j++] = '\n';
             clean_html[j] = '\0';
             for (space = 0; space < tabs; space++) 
                 strcat(clean_html, " ");
         }
         else 
         {
            clean_html[j++] = html[i++];
            clean_html[j] = '\0';
         }
     }
     printf("The beautified HTML code is : \n\n %s", clean_html);
     free(clean_html);
     return 0;
 }