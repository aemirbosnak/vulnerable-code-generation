//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_FORTUNES 50
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char fortune[MAX_FORTUNE_LENGTH];
    int length;
} fortune_t;

fortune_t fortunes[MAX_FORTUNES] = {
    {"You will find true love."},
    {"You will have good luck today."},
    {"A new opportunity will come your way."},
    {"You will be successful in your endeavors."},
    {"You will receive unexpected news."},
    {"You will make a new friend."},
    {"You will travel to an exciting destination."},
    {"You will overcome a challenge."},
    {"You will have a happy and fulfilling life."},
    {"You will achieve your dreams."},
    {"You will be blessed with good health."},
    {"You will experience great joy."},
    {"You will find peace and tranquility."},
    {"You will be surrounded by love and happiness."},
    {"You will have a prosperous future."},
    {"You will be admired and respected."},
    {"You will be rewarded for your hard work."},
    {"You will have a positive impact on others."},
    {"You will have a successful career."},
    {"You will have a comfortable and secure life."},
    {"You will have a strong and supportive family."},
    {"You will be blessed with abundance and wealth."},
    {"You will have a happy and loving relationship."},
    {"You will have a bright and promising future."},
    {"You will be successful in your studies."},
    {"You will have a happy and fulfilling marriage."},
    {"You will have a successful and fulfilling career."},
    {"You will be blessed with good fortune and success."},
    {"You will have a happy and prosperous life."},
    {"You will have a healthy and active lifestyle."},
    {"You will have a creative and fulfilling life."},
    {"You will have a peaceful and harmonious life."},
    {"You will be blessed with happiness and contentment."},
    {"You will have a successful and rewarding career."},
    {"You will have a happy and fulfilling family life."},
    {"You will have a prosperous and abundant life."},
    {"You will have a happy and fulfilling love life."},
    {"You will have a successful and lucrative business."},
    {"You will have a happy and healthy life."},
    {"You will have a happy and successful life."},
    {"You will have a prosperous and successful career."},
    {"You will have a happy and prosperous life."},
    {"You will have a happy and successful marriage."},
    {"You will have a happy and fulfilling life."},
    {"You will have a happy and successful life."},
    {"You will have a happy and prosperous life."},
    {"You will have a happy and successful life."}
};

void generate_fortune() {
    int i = rand() % MAX_FORTUNES;
    printf("%s\n", fortunes[i].fortune);
}

int main() {
    srand(time(NULL));
    int num_fortunes;
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &num_fortunes);
    for (int i = 0; i < num_fortunes; i++) {
        generate_fortune();
    }
    return 0;
}