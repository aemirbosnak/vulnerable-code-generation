//FormAI DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1000 // Maximum length for a database query
#define MAX_RESULTS 100 // Maximum number of results to display

int runQuery(char* query){
    /*
    This function takes a database query as input and returns the number of
    results that match the query. It uses a paranoid approach to avoid any
    SQL injection attacks.
    */

    // Check if the query contains any invalid characters
    const char *invalid_chars = "'\";()";
    for(int i=0; i<strlen(invalid_chars); i++){
        if(strchr(query, invalid_chars[i]) != NULL){
            printf("Illegal characters in query\n");
            return -1;
        }
    }

    // Prepare the query and try to execute it
    char full_query[MAX_QUERY_LENGTH];
    snprintf(full_query, sizeof(full_query), "SELECT * FROM users WHERE name='%s' OR email='%s';", query, query);
    // In this paranoid approach, we only allow queries that search for a user by name or email
    // Any other queries will be rejected as potentially malicious

    // Execute the query and retrieve the results
    printf("Running query: %s\n", full_query);

    // .. code to execute the query and fetch the results ..

    // Return the number of results
    int num_results = rand() % MAX_RESULTS;
    printf("Found %d results\n", num_results);
    return num_results;
}

int main(){
    // Example usage
    char query[MAX_QUERY_LENGTH];
    printf("Enter a name or email to search for: ");
    scanf("%s", query);

    int num_results = runQuery(query);
    if(num_results < 0){
        printf("Error running query\n");
        return 1;
    }

    // Display the results
    printf("Results:\n");
    for(int i=0; i<num_results; i++){
        // .. code to display each result ..
    }

    return 0;
}