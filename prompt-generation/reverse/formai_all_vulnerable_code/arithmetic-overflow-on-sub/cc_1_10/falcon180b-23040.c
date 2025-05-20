//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
    char word[10];
    int count;
}word_count;

int compare(const void *a, const void *b)
{
    return strcmp(*(char **)a,*(char **)b);
}

void count_words(char *str, word_count *arr, int n)
{
    char *token;
    int i=0;
    token=strtok(str," \t\n\r\f\v,.?!;:");
    while(token!=NULL)
    {
        if(i>=n)
        {
            printf("\nError: Array size is too small\n");
            exit(0);
        }
        strcpy(arr[i].word,token);
        arr[i].count=1;
        i++;
        token=strtok(NULL," \t\n\r\f\v,.?!;:");
    }
}

void sort_array(word_count *arr, int n)
{
    qsort(arr,n,sizeof(word_count),compare);
}

void print_array(word_count *arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s : %d\n",arr[i].word,arr[i].count);
    }
}

int main()
{
    FILE *fp;
    char ch;
    char *str=NULL;
    size_t len=0;
    ssize_t read;
    word_count arr[100];
    int n=0;
    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("\nError: Unable to open file\n");
        exit(0);
    }
    while((read=getline(&str,&len,fp))!=-1)
    {
        str[read-1]='\0';
        count_words(str,arr,n);
        n++;
    }
    fclose(fp);
    sort_array(arr,n);
    print_array(arr,n);
    return 0;
}