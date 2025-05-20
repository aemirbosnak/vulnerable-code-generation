//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include<stdio.h>
#include<string.h>

int main()
{
    char file[20];
    int i, j, k, n, flag;
    printf("Enter the file name: ");
    scanf("%s", file);

    //checking for virus in file name
    if(strstr(file, "virus")!=NULL || strstr(file, "trojan")!=NULL || strstr(file, "malware")!=NULL)
        printf("File name seems to be suspicious\n");

    FILE *fp;

    fp = fopen(file, "r");

    if(fp == NULL)
        printf("File could not be opened\n");
    else
    {
        char buffer[1000];
        fgets(buffer, 1000, fp);
        n = strlen(buffer);
        for(i=0; i<n; i++)
        {
            if(buffer[i]==' ')
            {
                flag = 0;
                for(j=0; j<6 && i+j<n; j++)
                {
                    if(buffer[i+j] == ' ')
                        break;

                    if(buffer[i+j] == 'm' && buffer[i+j+1] == 'a' && buffer[i+j+2] == 'l' && buffer[i+j+3] == 'w' && buffer[i+j+4] == 'a' && buffer[i+j+5] == 'r' && (i+j+6>=n || buffer[i+j+6] == ' ' || (buffer[i+j+6] == '.' && (i+j+7>=n || buffer[i+j+7] == ' '))))
                    {
                        printf("Malware detected at position %d\n", i);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                    break;
            }
        }
        fclose(fp);

        if(flag != 1)
            printf("File seems to be safe\n");
    }

    return 0;
}