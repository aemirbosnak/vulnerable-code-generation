//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int money=1000;
int bet;

int start();
int game(int n1,int n2,int n3,int n4,int n5);
int win(int amount);
int lose(int amount);
int hand(int c[5],char *n[5]);

int main()
{
    printf("\n\n\t\tWelcome to C Poker Game\n\n");
    printf("\n\n********Instructions********\n\n");
    printf("\t-> You start with $1000\n");
    printf("\t-> Bet amounts between $10 to $500\n");
    printf("\t-> See your hand\n");
    printf("\t-> Can choose to fold or raise\n\n");

    printf("\n\nReady to Play?\n\n");

    start();

    return 0;
}

int start()
{
    int n1,n2,n3,n4,n5;

    printf("Your total money: $%d\n",money);

    do
    {
        printf("Bet Amount: $");
        scanf("%d",&bet);

        if(bet<money)
        {
            int deck[52];
            int card=1,i,j,count;

            for(i=0;i<52;i++)
                deck[i]=(i%13)+1;

            srand(time(NULL));
            for(i=0;i<52;i++)
            {
                j=(rand()%51)+1;
                count=deck[i];
                deck[i]=deck[j];
                deck[j]=count;
            }

            n1=deck[0],n2=deck[1],n3=deck[2],n4=deck[3],n5=deck[4];

            if(game(n1,n2,n3,n4,n5)==1)
                money+=win(bet);
            else
                money=lose(bet);

            printf("Money Remaining: $%d\n",money);
        }
        else
            printf("\n\nYou don't have enough money!! Please try again\n\n");

    }while(money>0);

    printf("Game Over!!");

    return 0;
}

int game(int n1,int n2,int n3,int n4,int n5)
{
    int c[5]={n1,n2,n3,n4,n5};
    char *n[5];

    int i,j,t;
    for(i=0;i<5;i++)
        for(j=i+1;j<5;j++)
            if(c[j]<c[i])
            {
                t=c[i];
                c[i]=c[j];
                c[j]=t;
            }

    do
    {
        printf("\n\nYour hand is: \n\n");
        for(i=0;i<5;i++)
        {
            switch(c[i])
            {
                case 1 : n[i]="Ace";
                         break;

                case 11 : n[i]="Jack";
                         break;

                case 12 : n[i]="Queen";
                         break;

                case 13 : n[i]="King";
                         break;

                default : n[i]=c[i];
                          break;

            }
            printf("%s ",n[i]);
        }

        printf("\n\nEnter 1 to raise or 2 to fold: ");
        scanf("%d",&t);

        if(t==1)
        {
            printf("\n\nYour new cards are: \n\n");

            int temp;

            for(i=0;i<2;i++)
            {
                temp=(rand()%51)+1;
                c[i]=temp;
            }

            for(i=0;i<5;i++)
            {
                switch(c[i])
                {
                    case 1 : n[i]="Ace";
                             break;

                    case 11 : n[i]="Jack";
                             break;

                    case 12 : n[i]="Queen";
                             break;

                    case 13 : n[i]="King";
                             break;

                    default : n[i]=c[i];
                              break;

                }
                printf("%s ",n[i]);
            }

            /* Checking Hand */

            if(c[0]==c[1] && c[1]==c[2] && c[2]==c[3] && c[3]==c[4])
                return 1;

            if((c[0]+1)==c[1] && (c[1]+1)==c[2] && (c[2]+1)==c[3] && (c[3]+1)==c[4])
                return 1;

            return 0;
        }
        else
            return 0;
    }while(t!=0);   
}

int win(int amount)
{
    printf("\n\nCongratulations, You have won $%d!!",amount);
    return amount;
}

int lose(int amount)
{
    printf("\n\nOops, You have lost $%d!!",amount);
    return -amount;
}

int hand(int c[5],char *n[5])
{
    int i;

    /* Checking Hand */

    if(c[0]==c[1] && c[1]==c[2] && c[2]==c[3] && c[3]==c[4])
        return 1;

    if((c[0]+1)==c[1] && (c[1]+1)==c[2] && (c[2]+1)==c[3] && (c[3]+1)==c[4])
        return 1;

    return 0;
}