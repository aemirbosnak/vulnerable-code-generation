//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp1, *fp2;
    char filename[30];
    char watermark[100] = "Hello World! This is a watermarked file.";
    char ch;
    int len, i = 0, j = 0;

    printf("Enter filename to be watermarked: ");
    scanf("%s", filename);

    fp1 = fopen(filename, "r");
    if(fp1 == NULL)
    {
        printf("Error opening file.");
        exit(0);
    }

    len = strlen(watermark);
    
    fp2 = fopen("WatermarkedFile.txt", "w");
    if(fp2 == NULL)
    {
        printf("Error opening file.");
        exit(0);
    }

    while((ch = fgetc(fp1)) != EOF)
    {
        if(i < len)
        {
            fputc(watermark[i], fp2);
            i++;
            continue;
        }
        
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Watermark sucessfully added to file.");

    return 0;
}