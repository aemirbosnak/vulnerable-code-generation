//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FORTUNES 50

typedef struct {
    char fortune[80];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will meet a tall, dark stranger."},
    {"A great adventure awaits you."},
    {"You will come into a large sum of money."},
    {"Beware of a friend who is not what they seem."},
    {"You will find true love before the end of the year."},
    {"A long-lost relative will return to your life."},
    {"You will experience a major life change."},
    {"A new job opportunity will present itself."},
    {"You will receive unexpected good news."},
    {"A secret will be revealed to you."},
    {"You will have a lucky streak."},
    {"You will travel to a far-off land."},
    {"You will achieve a lifelong dream."},
    {"You will discover a hidden talent."},
    {"You will make a new friend who will be very important to you."},
    {"You will overcome a great obstacle."},
    {"You will learn an important life lesson."},
    {"You will have a happy and fulfilling life."},
    {"You will be blessed with good health and longevity."},
    {"You will find peace and contentment in your life."},
    {"You will experience great success in your career."},
    {"You will have a happy and loving marriage."},
    {"You will be surrounded by love and support from family and friends."},
    {"You will find happiness in the simple things in life."},
    {"You will be admired and respected by those around you."},
    {"You will have a positive impact on the lives of others."},
    {"You will be remembered fondly by future generations."},
    {"You will leave a lasting legacy."},
    {"You will find joy in helping others."},
    {"You will discover the true meaning of happiness."},
    {"You will find inner peace and harmony."},
    {"You will be blessed with creativity and inspiration."},
    {"You will have a strong connection to your spirituality."},
    {"You will be guided by a higher power."},
    {"You will have the courage to follow your dreams."},
    {"You will be a source of inspiration to others."},
    {"You will have a deep understanding of the universe."},
    {"You will find your true purpose in life."},
    {"You will be a beacon of hope to those in need."},
    {"You will have a powerful influence on the world around you."},
    {"You will experience profound love and compassion."},
    {"You will be a force for positive change in the world."},
    {"You will achieve enlightenment and transcendence."}
};

void *thread_function(void *arg) {
    int thread_id = (int) arg;
    srand(time(NULL) + thread_id);
    int fortune_index = rand() % MAX_FORTUNES;
    printf("Thread %d says: %s\n", thread_id, fortunes[fortune_index].fortune);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;

    srand(time(NULL));
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}