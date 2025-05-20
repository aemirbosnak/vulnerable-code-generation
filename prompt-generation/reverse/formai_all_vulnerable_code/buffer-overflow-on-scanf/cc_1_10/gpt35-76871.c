//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*STRUCT TO HOLD SANITIZED URL*/
typedef struct {
    char protocol[8];
    char domain[256];
    int port;
    char path[1024];
    char query[1024];
} sanitized_url;

/*STRUCT TO HOLD UNSANITIZED URL*/
typedef struct {
    char url[2048];
} unsanitized_url;

/*FUNCTION TO CHECK IF URL IS VALID*/
bool is_valid_url(char *url){
    char *protocols[] = {"http://", "https://"};
    bool has_protocol = false;
    for(int i=0; i<2; i++){
        if(strncmp(url, protocols[i], strlen(protocols[i]))==0){
            has_protocol = true;
            break;
        }
    }
    if(!has_protocol){
        printf("Error: Invalid URL\n");
        return false;
    }
    return true;
}

/*FUNCTION TO PARSE URL*/
void parse_url(char *url, sanitized_url *surl){
    char *protocol_end = strstr(url, "://");
    int protocol_len = protocol_end - url;
    strncpy(surl->protocol, url, protocol_len);
    surl->protocol[protocol_len] = '\0';

    char *path_start = strchr(protocol_end+3, '/');
    int path_len = strlen(path_start);
    strcpy(surl->path, path_start);

    char *query_start = strchr(path_start, '?');
    if(query_start){
        int query_len = strlen(query_start);
        strncpy(surl->query, query_start, query_len);
        surl->query[query_len] = '\0';
        strncpy(surl->domain, path_start, query_start-path_start);
        surl->domain[query_start-path_start] = '\0';
    }else{
        strcpy(surl->domain, path_start);
    }

    char *port_start = strchr(surl->domain, ':');
    if(port_start){
        surl->port = atoi(port_start+1);
        *port_start = '\0';
    }else{
        if(strcmp(surl->protocol, "http")==0){
            surl->port = 80;
        }else{
            surl->port = 443;
        }
    }
}

/*FUNCTION TO PRINT SANITIZED URL*/
void print_sanitized_url(sanitized_url *surl){
    printf("Protocol: %s\n", surl->protocol);
    printf("Domain: %s\n", surl->domain);
    printf("Port: %d\n", surl->port);
    printf("Path: %s\n", surl->path);
    printf("Query: %s\n", surl->query);
}

/*FUNCTION TO SANITIZE URL*/
sanitized_url sanitize_url(unsanitized_url *url){
    sanitized_url surl;
    if(!is_valid_url(url->url)){
        strcpy(surl.protocol, "");
        strcpy(surl.domain, "");
        surl.port = 0;
        strcpy(surl.path, "");
        strcpy(surl.query, "");
    }else{
        parse_url(url->url, &surl);
    }
    return surl;
}

int main(){
    unsanitized_url uurl;

    /*GET UNSANITIZED URL FROM USER*/
    printf("Enter URL: ");
    scanf("%s", uurl.url);

    sanitized_url surl = sanitize_url(&uurl);

    printf("\nSanitized URL:\n");
    print_sanitized_url(&surl);

    return 0;
}