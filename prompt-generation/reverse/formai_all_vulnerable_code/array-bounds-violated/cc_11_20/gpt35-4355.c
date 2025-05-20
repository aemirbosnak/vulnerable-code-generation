//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int main ()
{
    char log[MAX];
    char sus[MAX][MAX];
    int count=0,i=0,j,k,len,c,flag=0;
    FILE *fp;
    fp=fopen("audit.log","r"); // open the log file
    if(fp==NULL)
    {
        printf("Audit log file not found.\n");
        exit(1);
    }
    printf("Analysing the audit log file...\n");
    while(!feof(fp))
    {
        fgets(log,MAX,fp); // read each line of the log file
        len=strlen(log)-1; // remove the newline character from each line
        if(log[len]=='\n')
        {
            log[len]='\0';
            len--;
        }
        c=0;
        for(j=0;j<len;j++)
        {
            if(log[j]==' ')
            {
                c++; // count the number of spaces in each line
            }
            if(c==2)
            {
                flag=1; // set flag if the third space is encountered
            }
            if(c==3)
            {
                flag=0; // reset flag if the fourth space is encountered
            }
            if(flag==1)
            {
                sus[i][k]=log[j]; // copy the suspicious IP address from the line
                k++;
            }
            if(flag==0)
            {
                sus[i][k]='\0'; // terminate the string
                count++;
                i++;
                k=0;
                break;
            }
        }
    }
    fclose(fp); // close the log file
    printf("%d IP addresses found suspicious:\n",count);
    for(j=0;j<i;j++)
    {
        printf("%d. %s\n",j+1,sus[j]);
    }
    return 0;
}