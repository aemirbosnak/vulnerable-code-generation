//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/evp.h>

#define NUM_THREADS 2

struct thread_data {
    int thread_id;
    char message[100];
    unsigned char hash_output[EVP_MAX_MD_SIZE];
    unsigned int hash_length;
};

void *hash_message(void *thread_arguments) {
    struct thread_data *data;
    data = (struct thread_data *) thread_arguments;
    
    EVP_MD_CTX *md_context;
    const EVP_MD *md;
    int message_length;
    
    OpenSSL_add_all_digests();
    md = EVP_get_digestbyname("SHA256");

    md_context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(md_context, md, NULL);
    EVP_DigestUpdate(md_context, data->message, strlen(data->message));
    EVP_DigestFinal_ex(md_context, data->hash_output, &data->hash_length);
    
    EVP_MD_CTX_free(md_context);

    pthread_exit(NULL);
}

int main() {
    int rc, t;
    char input_message[100];
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    printf("Enter message to be hashed: ");
    scanf("%s", input_message);

    for(t=0; t<NUM_THREADS; t++) {
        td[t].thread_id = t;
        strcpy(td[t].message, input_message);
        rc = pthread_create(&threads[t], NULL, hash_message, (void *) &td[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for(t=0; t<NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        
        printf("Thread %d completed: Hash output is ", t);
        for(int i=0; i<td[t].hash_length; i++) {
            printf("%02x", td[t].hash_output[i]);
        }
        printf("\n");
    }

    pthread_exit(NULL);
    
    return 0;
}