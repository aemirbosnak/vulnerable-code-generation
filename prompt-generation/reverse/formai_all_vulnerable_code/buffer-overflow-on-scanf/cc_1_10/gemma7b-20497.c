//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 1024

typedef struct Key
{
    char key[MAX_KEY_SIZE];
    int key_size;
} Key;

void generate_key(Key *key)
{
    key->key_size = rand() % MAX_KEY_SIZE;
    for (int i = 0; i < key->key_size; i++)
    {
        key->key[i] = (rand() % 26) + 'a';
    }
}

int encrypt_file(Key *key, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }

    char buffer[1024];
    int read_size = 0;

    while ((read_size = fread(buffer, 1, 1024, fp)) > 0)
    {
        for (int i = 0; i < read_size; i++)
        {
            buffer[i] ^= key->key[i % key->key_size];
        }

        fwrite(buffer, 1, read_size, fp);
    }

    fclose(fp);

    return 0;
}

int main()
{
    Key key;
    generate_key(&key);

    char filename[256];
    printf("Enter file name: ");
    scanf("%s", filename);

    encrypt_file(&key, filename);

    printf("File encrypted successfully.\n");

    return 0;
}