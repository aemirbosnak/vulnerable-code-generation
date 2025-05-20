//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    FILE *fp=fopen("index.html", "r");
    FILE *wfp=fopen("output.html","w");
    if (fp==NULL)
    {
        printf("File not found");
        exit(0);
    }
    int indent=0;
    char ch, prevch;
    while (ch=fgetc(fp))
    {
        if(ch==-1)
            break;
        if(ch=='\n')
        {
            fputc('\n', wfp);
            for(int i=0;i<indent;i++)
                fputc('\t', wfp);
        }
        else if(ch=='<')
        {
            if(prevch=='\n')
            {
                for(int i=0;i<indent;i++)
                    fputc('\t', wfp);
            }
            fputc(ch, wfp);
            if(fgetc(fp)=='/')
            {
                indent--;
            }
            else
            {
                indent++;
                fseek(fp, -1, SEEK_CUR);
            }
        }
        else if(ch=='>')
        {
            fputc(ch, wfp);
            if(fgetc(fp)=='\n')
            {
                fputc('\n', wfp);
                for(int i=0;i<indent;i++)
                    fputc('\t', wfp);
            }
            else
                fseek(fp, -1, SEEK_CUR);
        }
        else
            fputc(ch,wfp);
        prevch=ch;
    }
    fclose(fp);
    fclose(wfp);
    return 0;
}