//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Structure for holding the fortunes
struct fortune{
    char text[100];
};

//Function to generate a random number
int randNum(){
    return rand()%100;
}

//Function to print a fortune
void printFortune(struct fortune* f){
    printf("%s\n",f->text);
}

//Function to generate a random fortune
struct fortune generateFortune(){
    struct fortune f;
    f.text[0]='\0';
    
    //Love
    if(randNum()<33){
        strcat(f.text,"You will find love soon. ");
    }
    //Money
    else if(randNum()<66){
        strcat(f.text,"Money is coming your way. ");
    }
    //Travel
    else if(randNum()<99){
        strcat(f.text,"You will go on a trip soon. ");
    }
    //Miscellaneous
    else{
        strcat(f.text,"Something unexpected will happen. ");
    }
    
    return f;
}

//Recursive function to tell fortunes
void fortuneTeller(int num){
    srand(time(0));
    struct fortune f;
    
    //Tell fortunes
    for(int i=0;i<num;i++){
        f=generateFortune();
        printFortune(&f);
    }
}

int main(){
    int num;
    
    //Get number of fortunes to tell
    printf("How many fortunes do you want to hear? ");
    scanf("%d",&num);
    
    //Call fortuneTeller function
    fortuneTeller(num);
    
    return 0;
}