//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,m,n,p;
    int sudoku[9][9];
    int flag=0;
    FILE *fp;
    char filename[20];
    printf("Enter the name of the file: ");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(fscanf(fp,"%d",&sudoku[i][j])!=1)
            {
                printf("Error in file format");
                exit(0);
            }
        }
    }
    fclose(fp);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                for(k=1;k<=9;k++)
                {
                    flag=0;
                    for(m=0;m<9;m++)
                    {
                        if(sudoku[i][m]==k)
                        {
                            flag=1;
                            break;
                        }
                    }
                    for(n=0;n<9;n++)
                    {
                        if(sudoku[n][j]==k)
                        {
                            flag=1;
                            break;
                        }
                    }
                    for(p=0;p<9;p++)
                    {
                        if(sudoku[i/3*(p/3)][j/3*(p/3)]==k)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        sudoku[i][j]=k;
                        break;
                    }
                }
            }
        }
    }
    printf("\nThe solution of the Sudoku is:\n");
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
    return 0;
}