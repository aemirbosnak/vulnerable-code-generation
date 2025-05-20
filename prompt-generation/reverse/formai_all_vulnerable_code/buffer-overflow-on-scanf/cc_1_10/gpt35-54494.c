//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include<stdio.h>
#include<string.h>

//declaring constants for the dimensions of the output ASCII art image
#define ROWS 7
#define COLS 75

//function to print the ASCII art image
void print_ascii_art(char message[])
{
    //2-D array to store the ASCII art image
    char ascii_art[ROWS][COLS];
    
    //initializing all elements of the array to blank spaces
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            ascii_art[i][j]=' ';
        }
    }
    
    //loop to fill up the ASCII art array with characters corresponding to the input text
    int n=strlen(message);
    for(int i=0;i<n;i++)
    {
        if(message[i]>='a' && message[i]<='z')   //if the character is a lowercase letter
        {
            //logic to fill up the array with the appropriate character sequence for the given letter
            int pos=(int)message[i]-97;
            int x=0,y=(pos*5)+3;
            ascii_art[x][y]=ascii_art[x+6][y]='_';
            ascii_art[x+1][y-1]=ascii_art[x+2][y-2]=ascii_art[x+3][y-2]=ascii_art[x+4][y-1]='/';
            ascii_art[x+1][y+1]=ascii_art[x+2][y+2]=ascii_art[x+3][y+2]=ascii_art[x+4][y+1]='\\';
        }
        else if(message[i]>='A' && message[i]<='Z')   //if the character is an uppercase letter
        {
            //logic to fill up the array with the appropriate character sequence for the given letter
            int pos=(int)message[i]-65;
            int x=0,y=(pos*6)+2;
            ascii_art[x+1][y]=ascii_art[x+5][y]='_';
            ascii_art[x+2][y-1]=ascii_art[x+3][y-1]=ascii_art[x+4][y-1]='|';
            ascii_art[x+2][y+1]=ascii_art[x+3][y+1]=ascii_art[x+4][y+1]='|';
            ascii_art[x][y-1]=ascii_art[x][y+1]=ascii_art[x+1][y-2]=ascii_art[x+1][y+2]='\\';
            ascii_art[x+1][y-3]=ascii_art[x+1][y+3]=ascii_art[x+2][y-4]=ascii_art[x+2][y+4]='\\';
            ascii_art[x+2][y-5]=ascii_art[x+2][y+5]=ascii_art[x+3][y-5]=ascii_art[x+3][y+5]='_';
            ascii_art[x+4][y-4]=ascii_art[x+4][y+4]=ascii_art[x+5][y-3]=ascii_art[x+5][y+3]='/';
        }
        else if(message[i]>='0' && message[i]<='9')   //if the character is a digit
        {
            //logic to fill up the array with the appropriate character sequence for the given digit
            int pos=(int)message[i]-48;
            int x=0,y=(pos*6)+2;
            ascii_art[x+1][y]=ascii_art[x+5][y]='_';
            ascii_art[x][y+1]=ascii_art[x][y+3]=ascii_art[x+5][y+1]=ascii_art[x+5][y+3]='|';
            ascii_art[x+1][y+4]=ascii_art[x+2][y+4]=ascii_art[x+3][y+4]='\\';
            ascii_art[x+4][y+1]=ascii_art[x+4][y+3]=ascii_art[x+5][y+2]=ascii_art[x+5][y+4]='/';
        }
    }
    
    //printing the full ASCII art image
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c",ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char input[50];
    printf("Welcome to the ASCII Art Generator!\n\n");
    printf("Enter the message you want to convert to ASCII art: ");
    scanf("%[^\n]",input);
    printf("\n");
    print_ascii_art(input);
    return 0;
}