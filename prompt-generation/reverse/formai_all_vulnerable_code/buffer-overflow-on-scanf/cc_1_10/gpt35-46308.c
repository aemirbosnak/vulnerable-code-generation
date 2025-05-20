//FormAI DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[100], search_word[100], replace_word[100], buf[1024];
    FILE *fp;
    int i, j, k, n, m;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter word to replace: ");
    scanf("%s", search_word);

    printf("Enter replacement word: ");
    scanf("%s", replace_word);

    fp = fopen(filename, "r+");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while(fgets(buf, sizeof(buf), fp))
    {
        n = strlen(buf);
        m = strlen(search_word);
        for(i=0; i<n-m; i++)
        {
            if(buf[i] == search_word[0])
            {
                k = i;
                for(j=1; j<m; j++)
                {
                    if(buf[++k] != search_word[j])
                        break;
                }
                if(j == m)
                {
                    fseek(fp, -(n-k), SEEK_CUR);
                    fputs(replace_word, fp);
                    fseek(fp, m-strlen(replace_word), SEEK_CUR);
                }
            }
        }
    }

    fclose(fp);

    printf("File updated successfully!\n");

    return 0;
}