//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DICT_FILE "dictionary.txt"

int main() {
    FILE *fp;
    char word[100];
    char *dict[100];
    int i, n;

    if ( (fp = fopen( DICT_FILE, "r" ) ) == NULL ) {
        printf( "Can't open dictionary file.\n" );
        exit( 1 );
    }

    fscanf( fp, "%s", word );
    n = 0;

    while ( fscanf( fp, "%s", word )!= EOF ) {
        dict[n] = strdup( word );
        n++;
    }

    fclose( fp );

    char *word2 = NULL;
    char *misspelled_words[100];
    int misspelled_count = 0;

    fp = fopen( "text.txt", "r" );
    while ( fscanf( fp, "%s", word )!= EOF ) {
        word2 = strdup( word );

        for ( i = 0; i < n; i++ ) {
            if ( strcmp( dict[i], word2 ) == 0 ) {
                free( word2 );
                break;
            }
        }

        if ( i == n ) {
            misspelled_words[misspelled_count] = strdup( word );
            misspelled_count++;
        }

        free( word2 );
    }

    fclose( fp );

    if ( misspelled_count == 0 ) {
        printf( "No misspelled words found.\n" );
    } else {
        printf( "Misspelled words:\n" );
        for ( i = 0; i < misspelled_count; i++ ) {
            printf( "%s\n", misspelled_words[i] );
        }
    }

    free( dict[0] );

    return 0;
}