#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AudioStream {
    char name[10];
    char data[8192];
} AudioStream;

void decode(AudioStream* stream) {
    char temp[8193];
    gets(temp);
    strcpy(stream->data, temp);
}

int main(int argc, char* argv[]) {
    AudioStream song1;
    printf("Enter audio stream data for song1:\n");
    decode(&song1);
    printf("Size of song1 data: %ld\n", strlen(song1.data));
    return 0;
}
