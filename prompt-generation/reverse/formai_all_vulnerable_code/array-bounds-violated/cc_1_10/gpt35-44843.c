//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

// Define the HTTPS port
#define HTTP_PORT 443

int main() {

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    // Create a SSL context and set the SSL method to TSLv1.2
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());

    // Turn off SSLv2 and SSLv3
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);

    // Create a TCP connection to the Google server
    BIO *bio = BIO_new_ssl_connect(ctx);
    BIO_set_conn_hostname(bio, "www.google.com:https");

    // Verify the server certificate
    if(SSL_get_verify_result(SSL_get_peer_certificate((SSL *)bio))!= X509_V_OK){
        printf("Certificate verification failed\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if(BIO_do_connect(bio) <= 0){
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }

    // Send a GET request to the server
    const char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    BIO_write(bio, request, strlen(request));

    // Read the server response
    char response[1024];
    int response_length;
    while((response_length = BIO_read(bio, response, 1023)) > 0){
        response[response_length] = '\0';
        printf("%s", response);
    }

    // Clean up
    BIO_free_all(bio);
    SSL_CTX_free(ctx);
    ERR_free_strings();
    EVP_cleanup();
    return 0;
}