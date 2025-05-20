//FormAI DATASET v1.0 Category: Image Classification system ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Image Classification System v1.0!!!\n");
    printf("Please select the type of image you would like to classify:\n");

    printf("1. Cute Animals\n");
    printf("2. Ugly People\n");
    printf("3. Lame Memes\n");
    printf("4. All of the Above\n");

    int choice;
    scanf("%d",&choice);

    srand(time(0)); //for random number generation
    int imageType = rand()%3; //generating a random number between 0 and 2

    if(choice==1){
        if(imageType==0){
            printf("You have selected Cute Animals and the generated image is a Cute Cat!!!\n");
        }
        else if(imageType==1){
            printf("You have selected Cute Animals and the generated image is a Cute Dog!!!\n");
        }
        else{
            printf("You have selected Cute Animals and the generated image is a Cute Bunny!!!\n");
        }
    }
    else if(choice==2){
        if(imageType==0){
            printf("You have selected Ugly People and the generated image is an Ugly Man!!!\n");
        }
        else if(imageType==1){
            printf("You have selected Ugly People and the generated image is an Ugly Woman!!!\n");
        }
        else{
            printf("You have selected Ugly People and the generated image is an Ugly Baby!!!\n");
        }
    }
    else if(choice==3){
        if(imageType==0){
            printf("You have selected Lame Memes and the generated image is a Dank Meme!!!\n");
        }
        else if(imageType==1){
            printf("You have selected Lame Memes and the generated image is a Cringe Meme!!!\n");
        }
        else{
            printf("You have selected Lame Memes and the generated image is a Bad Joke!!!\n");
        }
    }
    else if(choice==4){
        if(imageType==0){
            printf("You have selected All of the Above and the generated image is a Cute Cat!!!\n");
        }
        else if(imageType==1){
            printf("You have selected All of the Above and the generated image is an Ugly Man!!!\n");
        }
        else{
            printf("You have selected All of the Above and the generated image is a Dank Meme!!!\n");
        }
    }
    else{
        printf("Invalid Choice!!! Please enter a valid choice next time.\n");
    }
    return 0;
}