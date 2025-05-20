//FormAI DATASET v1.0 Category: File handling ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int age;
    char email[MAX_LEN];
} Person;

int main () {
    FILE *fp; 
    char filename[MAX_LEN];

    printf("My Love,\n");
    printf("Enter the filename where I will store our love story: ");
    scanf("%s", filename);

    fp = fopen(filename, "w"); 

    if (fp == NULL) {
        printf("Unable to open the file, I will try again later :(\n");
        exit(1);
    }

    printf("Great! Let's start our story!\n");

    printf("What's your name?\n");
    char name[MAX_LEN];
    scanf("%s", name);

    printf("What's your age?\n");
    int age;
    scanf("%d", &age);

    printf("What's your email?\n");
    char email[MAX_LEN];
    scanf("%s", email);

    Person you = { .name = name, .age = age, .email = email };
    fprintf(fp, "The love story began when I met %s, the most beautiful and intelligent person I have ever met. They were %d years old and their contact email was %s. ", you.name, you.age, you.email);

    printf("\nWhat's my name?\n");
    char myName[MAX_LEN];
    scanf("%s", myName);

    printf("What's my age?\n");
    int myAge;
    scanf("%d", &myAge);

    printf("What's my email?\n");
    char myEmail[MAX_LEN];
    scanf("%s", myEmail);

    Person me = { .name = myName, .age = myAge, .email = myEmail };
    fprintf(fp, "They caught my eye and I could not resist introducing myself. They later told me their name was %s. I remember being nervous and blushing as we talked. We exchanged contact information, and I couldn't wait to see them again. %s was %d years old and their email was %s. ", me.name, me.name, me.age, me.email);

    printf("\nDo you still remember what happened on our first date?\n");
    char firstDate[MAX_LEN];
    scanf(" %[^\n]%*c", firstDate);

    fprintf(fp, "%s Our first date was filled with laughter and smiles. I can still remember the way your eyes shimmered in the candlelight and the sound of your laughter ringing through my ears. It felt like a dream come true to be with you.\n", firstDate);

    printf("\nWhat did we do on our first anniversary?\n");
    char anniversary[MAX_LEN];
    scanf(" %[^\n]%*c", anniversary);

    fprintf(fp, "%s Our first anniversary was even more special than our first date. We went out to a fancy restaurant and danced the night away. It was magical being with you, and I will cherish that moment forever.\n", anniversary);

    printf("\nWhat is your favorite memory with me?\n");
    char memory[MAX_LEN];
    scanf(" %[^\n]%*c", memory);

    fprintf(fp, "%s We have shared so many wonderful memories together. From our walks in the park, to watching movies together, to traveling the world. My favorite memory with you though, is simply being with you. Just being able to talk to you and share our lives together is something I treasure above everything else.\n", memory);

    printf("\nFinally, what do you think the future holds for us?\n");
    char future[MAX_LEN];
    scanf(" %[^\n]%*c", future);

    fprintf(fp, "As I look to the future, I cannot imagine my life without you in it. I know that we will face challenges and obstacles, but I have no doubt that we will face them together. Our love is strong and unbreakable. %s\n", future);

    printf("\nI hope you enjoyed our love story. The file is saved as %s. I love you more than words can express.\n", filename);
    fprintf(fp, "I will always love you, forever and always.\n");

    fclose(fp);

    return 0;
}