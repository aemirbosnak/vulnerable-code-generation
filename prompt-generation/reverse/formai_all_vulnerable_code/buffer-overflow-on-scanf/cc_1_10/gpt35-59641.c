//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    char ch, log_file[20],search[20];
    int count = 0;
  
    printf("\nEnter the name of log file:");
    scanf("%s",log_file);
  
    fp = fopen(log_file,"r");
 
    if(fp == NULL)
    {
        printf("\n\nFile not found!!");
        exit(1);
    }
  
    printf("\nEnter the search string:");
    scanf("%s",search);
  
    printf("\nResultant lines are:");
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n' || ch == '\r')
        {
            char line[256];
            int len = strlen(search);
            int line_len = strlen(line);
            int i, found = 0;

            for(i = 0; i < line_len; i++)
            {
                if(line[i] == search[found])
                {
                    found++;
                    if(found == len)
                    {
                        printf("%s\n", line);
                        count++;
                        break;
                    }
                }
                else
                    found = 0;
            }
        }
    }
    if(count == 0)
        printf("\nNo line found!!");
 
    fclose(fp);
    return 0;
}